/*
	Name: UserModel
	Copyright: ̨�ݿƼ�ѧԺ
	Author: XMAO
	Date: 10/11/19 22:10
	Description: �û�����ģ��
*/

#include "ATMStorage.h"

/***************************************************************
* @brief �û���½
* @param name �˻���
* @param pass ����
**************************************************************/
struct User *  login_user(char *name,char *pass){
	struct User * user1;
	struct User user_fix; //�޸����Ͳ�����BUG 
	user_fix = get_user(name);
	user1 = &user_fix;
	if(strlen(user1->name) == 0) return NULL;
	if(strcmp(pass,user1->pass)) return NULL;
	return user1;
}
/***************************************************************
* @brief �½��û�
* @param name �˻���
* @param pass ����
**************************************************************/
void reg_user(char *name,char *pass){
	create_user(user(name,pass,0.0));
}
/***************************************************************
* @brief �����û�ģ��
* @param user �û��ṹ��
**************************************************************/
void save_user(struct User user){
	update_user(user);
};
/***************************************************************
* @brief �ж��û���Ǯ�Ƿ��㹻
* @param name �˻���
* @param money  ���
**************************************************************/
int hasMoney(char * name,double money){
    struct User user;
    user = get_user(name);
    if(user.money < money) return 0;
    return 1;
}
/***************************************************************
* @brief �����û���Ǯ
* @param name �˻���
* @param money  ���
**************************************************************/
void setMoney(char * name,double money){
    struct User user;
    user = get_user(name);
    user.money = money;
    update_user(user);
}
/***************************************************************
* @brief �����û����
* @param name �˻���
* @param money  ���
**************************************************************/
void takeMoney(char * name,double money){
    struct User user;
    user = get_user(name);
    user.money -= money ;
    update_user(user);
}
/***************************************************************
* @brief �����û���Ǯ
* @param name �˻���
* @param money  ���
**************************************************************/
void giveMoney(char * name,double money){
    struct User user;
    user = get_user(name);
    user.money += money ;
    update_user(user);
}
