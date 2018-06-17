#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define USR_NAME_LEN 16
#define USR_PWD_LEN 16
//账号
typedef struct usr_account_tag
{
	char usr_name[USR_NAME_LEN];  //用户名
	char usr_pwd[USR_PWD_LEN];   //密码
	char usr_role;  //用户权限（管理员权限为1，其他为0）
	struct usr_account_tag *pNext_Usr_Account;
}USR_ACCOUNT, *pUSR_ACCOUNT;
//学生信息
typedef struct usr_infor_tag
{
	int usr_id; //学号
	char usr_name[USR_NAME_LEN]; //姓名
	char usr_sex; //性别
	float usr_course_score[5];  //课程分数
	struct usr_infor_tag *pNext_Usr_Infor;

}USR_INFOR, *pUSR_INFOR;

//系统初始化函数,初始化内存中的学生信息链表和账号列表。
void system_init(const char* config_file_name, pUSR_ACCOUNT *pUsr_Account, pUSR_INFOR *pUsr_Infor);

//登录
char sign_in(pUSR_ACCOUNT *pUsr_Account);

//显示系统菜单
void show_system_menu(char role, pUSR_ACCOUNT *pUsr_Account,pUSR_INFOR *pUsr_Infor);

//显示菜单1，返回值决定是否返回系统菜单
int show_search_menu(char role, pUSR_INFOR *pUsr_Infor);

//显示所有学生信息（菜单1附属）
void show_all_stuInfo(pUSR_INFOR *pUsr_Infor);

//按照学号搜索学生信息（菜单1附属）
void show_stuInfo_by_id(pUSR_INFOR *pUsr_Infor);

//按照姓名搜索学生信息（菜单1附属）
void show_stuInfo_by_name(pUSR_INFOR *pUsr_Infor);

//增加学生信息（菜单2）
void add_stuInfo(pUSR_INFOR *pUsr_Infor);

//修改学生信息（菜单3）
void modify_stuInfo(pUSR_INFOR *pUsr_Infor);

//删除学生信息（菜单4）
void delete_stuInfo(pUSR_INFOR *pUsr_Infor);

//添加账号（菜单5）
void add_account(pUSR_ACCOUNT *pUsr_Account);

//修改账号信息（菜单6）
void modify_account(pUSR_ACCOUNT *pUsr_Account);

//删除账号（菜单7）
void delete_account(pUSR_ACCOUNT *pUsr_Account);

//查询账号信息（菜单8）
int show_acc_menu(pUSR_ACCOUNT *pUsr_Account);

//显示所有账号信息（菜单8附属）
void show_all_acc(pUSR_ACCOUNT *pUsr_Account);

//按照用户名查找用户信息（菜单8附属）
void show_acc_by_usr_name(pUSR_ACCOUNT *pUsr_Account);

//将学生信息和账号信息保存到文件里去
void save_data_to_file(const char* config_file_name, pUSR_ACCOUNT *pUsr_Account, pUSR_INFOR *pUsr_Infor);

