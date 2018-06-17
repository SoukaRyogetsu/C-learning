#include "head.h"

int main(int argc,char *argv[]) {
	pUSR_ACCOUNT usr_acchead = NULL;
	pUSR_INFOR usr_ifohead = NULL;
	system_init(argv[1],&usr_acchead,&usr_ifohead);  //将文件信息读入内存
	char role = sign_in(&usr_acchead); //获取输入权限
	if (role == '#') goto end;  //账号或密码输入错误，程序终止
	show_system_menu(role, &usr_acchead, &usr_ifohead);  //显示菜单
	save_data_to_file(argv[1], &usr_acchead, &usr_ifohead); //保存更改信息至文件
end:
	return 0;
}
