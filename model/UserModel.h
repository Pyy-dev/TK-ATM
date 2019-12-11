/*
	Name: UserModel
	Copyright: 台州科技学院
	Author: XMAO
	Date: 10/11/19 22:10
	Description: 用户操作模型
*/

#include "ATMStorage.h"

/***************************************************************
* @brief 用户登陆
* @param name 账户名
* @param pass 密码
**************************************************************/
struct User *  login_user(char *name,char *pass){
	struct User * user1;
	struct User user_fix; //修复类型不符的BUG 
	user_fix = get_user(name);
	user1 = &user_fix;
	if(strlen(user1->name) == 0) return NULL;
	if(strcmp(pass,user1->pass)) return NULL;
	return user1;
}
/***************************************************************
* @brief 新建用户
* @param name 账户名
* @param pass 密码
**************************************************************/
void reg_user(char *name,char *pass){
	create_user(user(name,pass,0.0));
}
/***************************************************************
* @brief 保存用户模型
* @param user 用户结构体
**************************************************************/
void save_user(struct User user){
	update_user(user);
};
/***************************************************************
* @brief 判断用户金钱是否足够
* @param name 账户名
* @param money  金额
**************************************************************/
int hasMoney(char * name,double money){
    struct User user;
    user = get_user(name);
    if(user.money < money) return 0;
    return 1;
}
/***************************************************************
* @brief 设置用户金钱
* @param name 账户名
* @param money  金额
**************************************************************/
void setMoney(char * name,double money){
    struct User user;
    user = get_user(name);
    user.money = money;
    update_user(user);
}
/***************************************************************
* @brief 拿走用户金额
* @param name 账户名
* @param money  金额
**************************************************************/
void takeMoney(char * name,double money){
    struct User user;
    user = get_user(name);
    user.money -= money ;
    update_user(user);
}
/***************************************************************
* @brief 给予用户金钱
* @param name 账户名
* @param money  金额
**************************************************************/
void giveMoney(char * name,double money){
    struct User user;
    user = get_user(name);
    user.money += money ;
    update_user(user);
}
