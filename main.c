#include<stdio.h>
#include<Windows.h>
#include "model/UserModel.h"
#include "view/main.h"
void OldUserLogin();//老用户登录 
void Menu_Select();//菜单选项 
void OldUserMenu(char * username);//老用户菜单选项 
void NewUserRegister();//新用户开户 
void DrawMoney(char * username);//取钱
void DepositMoney(char * username);//存钱 
void QueryMoney(char * username);//查询 
void ChangePassword();//修改密码 
void Remittance(char * username);//转账
 
int main(){
 	Menu_Select();
 	return 0;
}
void Menu_Select(){
 	int select = -1; //菜单选项 
 	MenuView_UnLogin(); //先登录在操作;
	scanf("%d",&select); //用输入选项 
	if(select == 1){
		OldUserLogin();
	}else if(select == 2){
		NewUserRegister();
	}else if(select == 3){
		ExitMessageView();
	}else{
		ErrorInputTips(3,MenuView_UnLogin);
		Menu_Select();
		return;
	}	
} 
void OldUserMenu(char * username){
	int select = -1; //菜单选项 
	MenuView_Login();
	scanf("%d",&select); //用输入选项 
	if(select == 1){
		DrawMoney(username);
	}else if(select == 2){
		DepositMoney(username);
	}else if(select == 3){
		QueryMoney(username);
	}else if(select == 4){
		ChangePassword(username);
	}else if(select == 5){
		Remittance(username);
	}else if(select == 6){
		ExitMessageView();
	}else{
		ErrorInputTips(6,MenuView_Login);
		OldUserMenu(username);
	}
}
void NewUserRegister(){
	char username[50],password[50],password_r[50];
	struct User user;
	RegUserView(username,password,password_r);
	if(!(strlen(password) >= 6 && strlen(password) <= 12)){
		InfoTips("密码必须大于等于6 小于等于12");
		Menu_Select();
		return;
	}
	if(strcmp(password,password_r) != 0){
		InfoTips("        两次密码不一致      ");
		Menu_Select();
		return ;
	}
	user = get_user(username); 
	if(strlen(user.name) != 0){
		InfoTips("       用户名已存在        ");
		Menu_Select();
		return ;
	}
	reg_user(username,password);
	InfoTips("     注册成功,请重新登陆    ");
	Menu_Select();
}
void DrawMoney(char * username){
	int select = -1; //菜单选项 
	DrawMoneyView();
	scanf("%d",&select); //用输入选项 
	if(select == 1){
		if(!hasMoney(username,100)){
			InfoTips("          余额不足          ");
			OldUserMenu(username);
			return;
		}
		takeMoney(username,100);
	}else if(select == 2){
		if(!hasMoney(username,500)){
			InfoTips("          余额不足          ");
			OldUserMenu(username);
			return;
		}
		takeMoney(username,500);
	}else if(select == 3){
		if(!hasMoney(username,1000)){
			InfoTips("          余额不足          ");
			OldUserMenu(username);
			return;
		}
		takeMoney(username,1000);
	}else if(select == 4){
		OldUserMenu(username);
	}
	InfoTips("           取款成功         ");
	OldUserMenu(username);
}
void DepositMoney(char * username){
	struct User user;
	int much = 0;
	double money = 0.0;
	DepositMoneyView();
	scanf("%d",&much);
	money = much * 100.0;
	giveMoney(username,money);
	DepositMoneyAnimation();
	InfoTips("          存款成功！        "); 
	OldUserMenu(username); 
}
void QueryMoney(char * username){
	struct User user;
	int select = -1; //菜单选项 
	user = get_user(username);
	QueryMoneyView(user.money);
	scanf("%d",&select); //用输入选项 
	if(select == 1){
		OldUserMenu(username);	
	}else if(select == 2){
		ExitMessageView();
	}else{
		ErrorInputTips(2,MenuView_Login);
		OldUserMenu(username);
	}
} 
void ChangePassword(char * username){
	char oldPass[50],newPass[50],newPass_r[50];
	ChangePasswordView(oldPass,newPass,newPass_r);
	struct User  * user;
	if(!(strlen(newPass) >= 6 && strlen(newPass) <= 12)){
		InfoTips("密码必须大于等于6 小于等于12");
		OldUserMenu(username);
		return;
	}
	if(strcmp(newPass,newPass_r) != 0){
		InfoTips("        两次密码不一致      ");
		OldUserMenu(username);
		return ;
	}
	user = login_user(username,oldPass);
	if(user == NULL){
		InfoTips("         旧密码错误!       ");
		OldUserMenu(username);
		return;
	}
	strcpy(user->pass,newPass);
	save_user(*user);
	InfoTips("    修改成功!请重新登陆!    ");
	Menu_Select();
}
void Remittance(char * username){
	char name[50];
	double money = 0.0;
	struct User user2;
	struct User user;
	RemittanceView(name,&money);
	if(!hasMoney(username,money)){
		InfoTips("          余额不足          ");
		OldUserMenu(username);
		return;
	}
	user2 = get_user(name);
	if(strlen(user2.name) == 0){
		InfoTips("       用户不存在        ");
		OldUserMenu(username);
		return ;
	}
	takeMoney(username,money);
	giveMoney(name,money);
	DepositMoneyAnimation();
	InfoTips("         转账成功          ");
	OldUserMenu(username);
} 
void OldUserLogin(){
		cls();
		char name[50];
		char password[50];
		printf("请输入你的账号：");
		scanf("%s",&name);
		printf("请输入你的密码：");
		scanf("%s",&password);
		/**用户登陆**/
		struct User  * user;
		user = login_user(name,password);
		if(user == NULL){
			InfoTips("        账号或密码错误      ");
			Menu_Select();
		}else{
			strcpy(name,user->name);
			OldUserMenu(name);
		}
}
