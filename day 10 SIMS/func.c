#include "head.h"

//系统初始化，预处理
void system_init(const char* config_file_name, pUSR_ACCOUNT *pUsr_Account, pUSR_INFOR *pUsr_Infor) {
	FILE *cog = fopen(config_file_name, "r+");
	char buf[255],usr_acc_add[256],usr_info_add[256];
	int line_acc = 0, line_info = 0, i, j;

	//初始化账户信息
	fgets(usr_acc_add, sizeof(usr_acc_add), cog);
	usr_acc_add[strlen(usr_acc_add) - 1] = '\0';  //删除路径末尾的换行符
	FILE *usr_acc = fopen((const char*)usr_acc_add, "r+"); // 获取用户账号信息文件所在路径
	if (usr_acc == NULL) {
		perror("fopen");
	}
	while (fgets(buf, sizeof(buf), usr_acc) != NULL) 
		line_acc++;
	fseek(usr_acc, 0, SEEK_SET);
	for (i = 0; i < line_acc; i++) {
		pUSR_ACCOUNT pusr_acc_new = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
		fscanf(usr_acc, "%s%s %c", pusr_acc_new->usr_name, pusr_acc_new->usr_pwd, &pusr_acc_new->usr_role);
		if (*pUsr_Account == NULL) {
			*pUsr_Account = pusr_acc_new;
		}
		else {
			pUSR_ACCOUNT pre=*pUsr_Account,pcur= *pUsr_Account;
			while (pcur != NULL) {
				pre = pcur;
				pcur = pcur->pNext_Usr_Account;
			}
			pre->pNext_Usr_Account = pusr_acc_new;
		}
	}
	
	//初始化学生信息
	fgets(usr_info_add, sizeof(usr_acc_add), cog);
	FILE *usr_info = fopen((const char*)usr_info_add, "r+");  //// 获取学生信息文件所在路径
	if (usr_info == NULL) {
		perror("fopen");
	}
	while (fgets(buf, sizeof(buf), usr_info) != NULL)
		line_info++;
	fseek(usr_info, 0, SEEK_SET);
	for (j = 0; j < line_info; j++) {
		pUSR_INFOR pusr_info_new = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
		fscanf(usr_info, "%d%s %c%f%f%f%f%f", &pusr_info_new->usr_id, pusr_info_new->usr_name, &pusr_info_new->usr_sex,&pusr_info_new->usr_course_score[0], &pusr_info_new->usr_course_score[1], &pusr_info_new->usr_course_score[2], &pusr_info_new->usr_course_score[3], &pusr_info_new->usr_course_score[4]);
		if (*pUsr_Infor == NULL) {
			*pUsr_Infor = pusr_info_new;
		}
		else {	
			int f = 0;
			pUSR_INFOR pre = *pUsr_Infor, pcur = *pUsr_Infor;
			while (pcur) {
				if (pcur->usr_id > pusr_info_new->usr_id) {
					if (pcur == *pUsr_Infor) {
						*pUsr_Infor = pusr_info_new;
						pusr_info_new->pNext_Usr_Infor = pcur;
						f = 1;		
						break;
					}
					else {
						pre->pNext_Usr_Infor = pusr_info_new;
						pusr_info_new->pNext_Usr_Infor = pcur;
						f = 1;
						break;
					}
				}
				pre=pcur;
				pcur = pcur->pNext_Usr_Infor;
			}
			if (f == 0) {
				pre->pNext_Usr_Infor = pusr_info_new;
			}
		}
	}
	fclose(usr_acc);
	fclose(usr_info);
}

//登陆模块,返回权限或者'#'
char sign_in(pUSR_ACCOUNT *pUsr_Account) {
	char name[USR_NAME_LEN], tmp_pwd[USR_PWD_LEN] = { 0 }, pwd[USR_PWD_LEN], c;
	int i = 0;
	printf("enter usr_name:");
	setbuf(stdin, NULL);
	scanf("%s", name);
	printf("enter usr_password:");
	while ((c = getch()) != '\r') {
		if (c != '\b') {
			tmp_pwd[i++] = c;
			printf("*");
		}
		else {
			if (i > 0) {
				tmp_pwd[--i] = '\0';
				printf("\b \b");
			}
		}
	}
	strcpy(pwd, tmp_pwd);
	int f = 0;
	pUSR_ACCOUNT pcur = *pUsr_Account;
	while (pcur) {
		if (strcmp(pcur->usr_name, name)==0 && strcmp(pcur->usr_pwd, pwd)==0 ) {
			f = 1;
			break;
		}
		else {
			pcur = pcur->pNext_Usr_Account;
		}	
	}
	if (f == 0) { 
		printf("\n账号或密码输入错误，程序终止\n");
		return '#';
	}
	else {
		return (pcur->usr_role);
	}
}

//菜单显示模块
void show_system_menu(char role, pUSR_ACCOUNT *pUsr_Account,pUSR_INFOR *pUsr_Infor) {
again:
	system("cls");
	int select,f,g;
	char c;
	if (role == '1') {  //管理员模式
		printf("1. search student information\n");  //查
		printf("2. add student information\n");     //增
		printf("3. update student information\n");  //改
		printf("4. delete student information\n");  //删
		printf("5. add user account\n");
		printf("6. update user account\n");
		printf("7. delete user account\n");
		printf("8. search user account\n");
		printf("9. exit\n");
	enter1:
		printf("please enter a number:");
		setbuf(stdin,NULL);
		scanf("%d", &select);
		switch (select){
			case 1: {
				f=show_search_menu(role, &(*pUsr_Infor));
				if (f == 1) goto again;
				else {
					setbuf(stdin, NULL);
					c = getchar();
					goto again;
				}
			}; break;
			case 2: {
				add_stuInfo(&(*pUsr_Infor));
				setbuf(stdin, NULL);
				c = getchar();
				goto again;
			}; break;
			case 3: {	
				modify_stuInfo(&(*pUsr_Infor));
				setbuf(stdin, NULL);
				c = getchar();
				goto again;
			}; break;
			case 4: {
				delete_stuInfo(&(*pUsr_Infor));
				setbuf(stdin, NULL);
				c = getchar();
				goto again;
			}; break;
			case 5: {	
				add_account(&(*pUsr_Account));
				setbuf(stdin, NULL);
				c = getchar();
				goto again;
			}; break;
			case 6: {	
				modify_account(&(*pUsr_Account));
				setbuf(stdin, NULL);
				c = getchar();
				goto again;
			}; break;
			case 7: {	
				delete_account(&(*pUsr_Account));
				setbuf(stdin, NULL);
				c = getchar();
				goto again;
			}; break;
			case 8: {	
				g = show_acc_menu(&(*pUsr_Account));
				if (g == 1) goto again;
				else {
					setbuf(stdin, NULL);
					c = getchar();
					goto again;
				}
			}; break;
			case 9: {	
				//什么也不做
			}; break;
			default: {
				printf("error!please ensure the number you enter is valid\n");
				goto enter1;
			}
		}
	}
	else {
		printf("1. search student information\n");
		printf("2. exit\n");
	enter0:
		printf("please enter a number:");
		setbuf(stdin, NULL);
		scanf("%d", &select);
		switch (select) {
		case 1: {
			f=show_search_menu(role,&(*pUsr_Infor));
			if (f == 1) goto again;
			else {
				setbuf(stdin, NULL);
				c = getchar();
				goto again;
			}
		}; break;
		case 2: {	
			//什么也不做
		}; break;
		default: {
			printf("error!please ensure the number you enter is valid\n");
			goto enter0;
		}
		}
	}
}

//查询学生信息功能时菜单（菜单1）
int show_search_menu(char role, pUSR_INFOR *pUsr_Infor) {
	system("cls");
	int select,f=0;
	if (role == '1') {
		printf("1. search all\n");
		printf("2. search by name\n");
		printf("3. search by id\n");
		printf("4. return\n");
	enter1:
		printf("please enter a number:");
		setbuf(stdin, NULL);
		scanf("%d", &select);
		switch (select) {
		case 1: {
			show_all_stuInfo(&(*pUsr_Infor));
		}; break;
		case 2: {
			show_stuInfo_by_name(&(*pUsr_Infor));
		}; break;
		case 3: {
			show_stuInfo_by_id(&(*pUsr_Infor));
		}; break;
		case 4: {
			f = 1;
			return f;
		}; break;
		default: {
			printf("error!please ensure the number you enter is valid\n");
			goto enter1;
		}
		}
	}
	else {
		printf("1. search by name\n");
		printf("2. search by id\n");
		printf("3. return\n");
	enter0:
		printf("please enter a number:");
		setbuf(stdin, NULL);
		scanf("%d", &select);
		switch (select) {
		case 1: {
			show_stuInfo_by_name(&(*pUsr_Infor));
		}; break;
		case 2: {
			show_stuInfo_by_id(&(*pUsr_Infor));
		}; break;
		case 3: {
			f = 1;
			return f;
		}; break;
		default: {
			printf("error!please ensure the number you enter is valid\n");
			goto enter0;
		}
		}
	}
	return f;
}

//显示所有学生信息（菜单1附属）
void show_all_stuInfo(pUSR_INFOR *pUsr_Infor) {
	system("cls");
	pUSR_INFOR pcur = *pUsr_Infor;
	while (pcur) {
		printf("%-10d\t%s\t%c\t%5.2f\t%5.2f\t%5.2f\t%5.2f\t%5.2f\n", pcur->usr_id, pcur->usr_name, pcur->usr_sex, pcur->usr_course_score[0], pcur->usr_course_score[1], pcur->usr_course_score[2], pcur->usr_course_score[3], pcur->usr_course_score[4]);
		pcur = pcur->pNext_Usr_Infor;
	}
	printf("按回车返回上一级菜单...");
}

//按照学号搜索学生信息（菜单1附属）
void show_stuInfo_by_id(pUSR_INFOR *pUsr_Infor) {
eback:
	printf("please enter the usr_id you want to search:");
	setbuf(stdin, NULL);
	pUSR_INFOR pcur = *pUsr_Infor;
	int want_id;
	scanf("%d", &want_id);
	while (pcur) {
		if (pcur->usr_id == want_id) {
			printf("%d\t%s\t%c\t%5.2f\t%5.2f\t%5.2f\t%5.2f\t%5.2f\n", pcur->usr_id, pcur->usr_name, pcur->usr_sex, pcur->usr_course_score[0], pcur->usr_course_score[1], pcur->usr_course_score[2], pcur->usr_course_score[3], pcur->usr_course_score[4]);
			printf("按回车返回上一级菜单...");
			return;
		}
		pcur = pcur->pNext_Usr_Infor;
	}
	printf("\nerror!The usr_id %d is not exist\n", want_id);
	goto eback;
}

//按照姓名搜索学生信息（菜单1附属）
void show_stuInfo_by_name(pUSR_INFOR *pUsr_Infor) {
eback:
	printf("please enter the usr_name you want to search:");
	pUSR_INFOR pcur = *pUsr_Infor;
	char want_name[USR_NAME_LEN];
	setbuf(stdin, NULL);
	scanf("%s", want_name);
	while (pcur) {
		if (strcmp(pcur->usr_name,want_name)==0) {
			printf("%d\t%s\t%c\t%5.2f\t%5.2f\t%5.2f\t%5.2f\t%5.2f\n", pcur->usr_id, pcur->usr_name, pcur->usr_sex, pcur->usr_course_score[0], pcur->usr_course_score[1], pcur->usr_course_score[2], pcur->usr_course_score[3], pcur->usr_course_score[4]);
			printf("按回车返回上一级菜单...");
			return;
		}
		pcur = pcur->pNext_Usr_Infor;
	}
	printf("\nerror!The student name %s is not exist\n", want_name);
	goto eback;
}

//添加学生信息（菜单2）
void add_stuInfo(pUSR_INFOR *pUsr_Infor) {
eback:
	printf("please enter the information of the student :\n");
	printf("format:usr_id usr_name usr_sex usr_score[i] (i from 0 to 4)\n");
	pUSR_INFOR p_in = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	pUSR_INFOR pcur = *pUsr_Infor, pre = *pUsr_Infor;
	setbuf(stdin, NULL);
	scanf("%d%s %c%f%f%f%f%f", &p_in->usr_id, p_in->usr_name, &p_in->usr_sex, &p_in->usr_course_score[0], &p_in->usr_course_score[1], &p_in->usr_course_score[2], &p_in->usr_course_score[3], &p_in->usr_course_score[4]);
	if (pcur == NULL) {  //链表为空
		*pUsr_Infor = p_in;
	}
	int f = 0;
	while (pcur) {
		if (pcur->usr_id > p_in->usr_id) {
			if (pcur == *pUsr_Infor) {  //插入结点为首结点
				*pUsr_Infor = p_in;
				p_in->pNext_Usr_Infor = pcur;
				f = 1;
				break;
			}
			pre->pNext_Usr_Infor = p_in;
			p_in->pNext_Usr_Infor = pcur;
			f = 1;
			break;
		}
		else if (pcur->usr_id < p_in->usr_id) {
			pre = pcur;
			pcur = pcur->pNext_Usr_Infor;
		}
		else {
			free(p_in);
			printf("\nerror!usr_id is not allowed to appear twice!\n");
			goto eback;
		}
	}
	if (f == 0) {
		pre->pNext_Usr_Infor = p_in;
	}
	printf("添加成功\n按回车返回上一级菜单...");
}

//修改学生信息（菜单3）
void modify_stuInfo(pUSR_INFOR *pUsr_Infor) {
	int moid;
eback:
	printf("please enter the usr_id of the stuInfo you want to modify:\n");
	setbuf(stdin, NULL);
	scanf("%d", &moid);
	pUSR_INFOR pcur = *pUsr_Infor, pre = *pUsr_Infor;
	pUSR_INFOR p_in = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	while (pcur) {
		if (pcur->usr_id == moid) {
			printf("please enter the information of the student you want to modify:\n");
			printf("format:usr_id usr_name usr_sex usr_score[i] (i from 0 to 4)\n");
			setbuf(stdin, NULL);
			scanf("%d%s %c%f%f%f%f%f", &p_in->usr_id, p_in->usr_name, &p_in->usr_sex, &p_in->usr_course_score[0], &p_in->usr_course_score[1], &p_in->usr_course_score[2], &p_in->usr_course_score[3], &p_in->usr_course_score[4]);
			if (p_in->usr_id != pcur->usr_id) {
				printf("\nerror!The usr_idis not allowed to modified\n");
				goto eback;
			}
			if (pcur == *pUsr_Infor) {
				*pUsr_Infor = p_in;
				p_in->pNext_Usr_Infor = pcur->pNext_Usr_Infor;
				printf("修改成功\n按回车返回上一级菜单...");
				return;
			}
			pre->pNext_Usr_Infor = p_in;
			p_in->pNext_Usr_Infor = pcur->pNext_Usr_Infor;
			printf("修改成功\n按回车返回上一级菜单...");
			return;
		}
		pre = pcur;
		pcur = pcur->pNext_Usr_Infor;
	}
	printf("\nerror!The usr_id %d is not exist\n",moid);
	goto eback;
}

//删除学生信息（菜单4）
void delete_stuInfo(pUSR_INFOR *pUsr_Infor) {
	int deid;
eback:
	printf("please enter the usr_id of the stuInfo you want to delete:\n");
	setbuf(stdin, NULL);
	scanf("%d", &deid);
	pUSR_INFOR pcur = *pUsr_Infor, pre = *pUsr_Infor;
	while (pcur) {
		if (pcur->usr_id == deid) {
			if (pcur == *pUsr_Infor) {
				*pUsr_Infor = pcur->pNext_Usr_Infor;
			}
			else
				pre->pNext_Usr_Infor = pcur->pNext_Usr_Infor;
			printf("学号 %d 学生信息已删除\n按回车返回上一级菜单...", deid);
			return;
		}
		pre = pcur;
		pcur = pcur->pNext_Usr_Infor;
	}
	printf("\nerror!The usr_id %d is not exist\n", deid);
	goto eback;
}

//添加账号（菜单5）
void add_account(pUSR_ACCOUNT *pUsr_Account) {
eback:
	printf("please enter the information of the account :\n");
	printf("format:usr_name usr_pwd usr_role('1' for administrator and '0' for others)\n");
	pUSR_ACCOUNT pcur = *pUsr_Account, pre = *pUsr_Account;
	pUSR_ACCOUNT p_in = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	setbuf(stdin, NULL);
	scanf("%s%s %c", p_in->usr_name, p_in->usr_pwd, &p_in->usr_role);
	if (pcur == NULL) {
		*pUsr_Account = pcur;
	}
	while (pcur) {
		if (strcmp(pcur->usr_name,p_in->usr_name)==0) {
			free(p_in);
			printf("\nerror! usr_name is not allowed to exist more than one!\n");
			goto eback;
		}
		pre = pcur;
		pcur = pcur->pNext_Usr_Account;
	}
	pre->pNext_Usr_Account = p_in;
	printf("按回车返回上一级菜单...");
}

//修改账号信息（菜单6）
void modify_account(pUSR_ACCOUNT *pUsr_Account) {
	char mo_name[USR_NAME_LEN];
eback:
	printf("please enter the user name of the account you want to modify:\n");
	setbuf(stdin, NULL);
	scanf("%s", &mo_name);
	pUSR_ACCOUNT pcur = *pUsr_Account, pre = *pUsr_Account;
	pUSR_ACCOUNT p_in = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	while (pcur) {
		if (strcmp(pcur->usr_name, mo_name) == 0) {
		ebacks:
			printf("please enter the information of the account you want to modify:\n");
			printf("format:usr_name usr_pwd usr_role('1' for administrator and '0' for others)\n");
			setbuf(stdin, NULL);
			scanf("%s%s %c", p_in->usr_name, p_in->usr_pwd, &p_in->usr_role);
			pUSR_ACCOUNT ppcur = *pUsr_Account, ppre = *pUsr_Account;
			while (ppcur) {
				if (strcmp(ppcur->usr_name, p_in->usr_name) == 0 ) {
					if (strcmp(ppcur->usr_name,mo_name)!=0){
						free(p_in);
						printf("\nerror! usr_name is not allowed to exist more than one!\n");
						goto ebacks;
					}
				}
				ppre = pcur;
				ppcur = ppcur->pNext_Usr_Account;
			}
			if (pcur == *pUsr_Account) {
				*pUsr_Account = p_in;
				p_in->pNext_Usr_Account = pcur->pNext_Usr_Account;
				printf("修改成功\n按回车返回上一级菜单...");
				return;
			}
			pre->pNext_Usr_Account = p_in;
			p_in->pNext_Usr_Account = pcur->pNext_Usr_Account;
			setbuf(stdin, NULL);
			printf("修改成功\n按回车返回上一级菜单...");
			return;
		}
		pre = pcur;
		pcur = pcur->pNext_Usr_Account;
	}
	printf("\nerror!The user name %s is not exist\n", mo_name);
	goto eback;
}

//删除账号（菜单7）
void delete_account(pUSR_ACCOUNT *pUsr_Account) {
	char de_name[USR_NAME_LEN];
eback:
	printf("please enter the user name of the account you want to delete:\n");
	setbuf(stdin, NULL);
	scanf("%s", de_name);
	pUSR_ACCOUNT pcur = *pUsr_Account, pre = *pUsr_Account;
	while (pcur) {
		if (strcmp(pcur->usr_name, de_name) == 0) {
			if (pcur == *pUsr_Account) {
				*pUsr_Account = pcur->pNext_Usr_Account;
			}
			else
				pre->pNext_Usr_Account = pcur->pNext_Usr_Account;
			printf("账号 %s 学生信息已删除\n按回车返回上一级菜单...", de_name);
			return;
		}
		pre = pcur;
		pcur = pcur->pNext_Usr_Account;
	}
	printf("\nerror!The user name %s is not exist\n", de_name);
	goto eback;
}

//查询账号信息（菜单8）
int show_acc_menu(pUSR_ACCOUNT *pUsr_Account) {
	system("cls");
	int select,f=0;
	char c;
	printf("1. search all\n");
	printf("2. search by usr_name\n");
	printf("3. return\n");
enter:
	printf("please enter a number:");
	setbuf(stdin, NULL);
	scanf("%d", &select);
	switch (select) {
	case 1: {
		show_all_acc(&(*pUsr_Account));
	}; break;
	case 2: {
		show_acc_by_usr_name(&(*pUsr_Account));
	}; break;
	case 3: {
		f = 1;
		return f;
	}; break;
	default:{
		printf("error!please ensure the number you enter is valid\n");
		goto enter;
	}
	}
	return f;
}

//显示所有账号信息（菜单8附属）
void show_all_acc(pUSR_ACCOUNT *pUsr_Account) {
	system("cls");
	pUSR_ACCOUNT pcur = *pUsr_Account;
	while (pcur) {
		printf("%-10s%-10s%c\n", pcur->usr_name, pcur->usr_pwd, pcur->usr_role);
		pcur = pcur->pNext_Usr_Account;
	}
	printf("按回车返回上一级菜单...");
}

//按照用户名查找用户信息（菜单8附属）
void show_acc_by_usr_name(pUSR_ACCOUNT *pUsr_Account) {
eback:
	printf("please enter the usr_name you want to search:");
	pUSR_ACCOUNT pcur = *pUsr_Account;
	char want_name[USR_NAME_LEN];
	setbuf(stdin, NULL);
	scanf("%s", want_name);
	while (pcur) {
		if (strcmp(pcur->usr_name, want_name) == 0) {
			printf("%-10s%-10s%c\n", pcur->usr_name, pcur->usr_pwd, pcur->usr_role);
			printf("按回车返回上一级菜单...");
			return;
		}
		pcur = pcur->pNext_Usr_Account;
	}
	printf("\nerror!The user name %s is not exist\n", want_name);
	goto eback;
}

//将学生信息和账号信息保存到文件里去
void save_data_to_file(const char* config_file_name, pUSR_ACCOUNT *pUsr_Account, pUSR_INFOR *pUsr_Infor) {
	FILE *cog = fopen(config_file_name, "r+");
	char buf[255], usr_acc_add[256], usr_info_add[256];
	//写账号信息
	fgets(usr_acc_add, sizeof(usr_acc_add), cog);
	usr_acc_add[strlen(usr_acc_add) - 1] = '\0';  //删除路径末尾的换行符
	FILE *usr_acc = fopen((const char*)usr_acc_add, "w+"); // 获取用户账号信息文件所在路径
	pUSR_ACCOUNT pcur_acc = *pUsr_Account;
	while (pcur_acc) {
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%-7s %-7s %c", pcur_acc->usr_name, pcur_acc->usr_pwd, pcur_acc->usr_role);
		fprintf(usr_acc, buf);
		if (pcur_acc->pNext_Usr_Account != NULL) {
			fprintf(usr_acc, "\n");
		}
		pcur_acc = pcur_acc->pNext_Usr_Account;
	}
	//写学生信息
	fgets(usr_info_add, sizeof(usr_acc_add), cog);
	FILE *usr_info = fopen((const char*)usr_info_add, "r+");  //// 获取学生信息文件所在路径
	pUSR_INFOR pcur_info = *pUsr_Infor;
	while (pcur_info) {
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%-7d\t%s\t%c\t%5.2f\t%5.2f\t%5.2f\t%5.2f\t%5.2f", pcur_info->usr_id, pcur_info->usr_name, pcur_info->usr_sex, pcur_info->usr_course_score[0], pcur_info->usr_course_score[1], pcur_info->usr_course_score[2], pcur_info->usr_course_score[3], pcur_info->usr_course_score[4]);
		fprintf(usr_info, buf);
		if (pcur_info->pNext_Usr_Infor != NULL) {
			fprintf(usr_info, "\n");
		}
		pcur_info = pcur_info->pNext_Usr_Infor;
	}
	fclose(usr_acc);
	fclose(usr_info);
}
