#include<stdio.h>
#include<Windows.h>
#include "model/UserModel.h"
#include "view/main.h"
void OldUserLogin();//���û���¼ 
void Menu_Select();//�˵�ѡ�� 
void OldUserMenu(char * username);//���û��˵�ѡ�� 
void NewUserRegister();//���û����� 
void DrawMoney(char * username);//ȡǮ
void DepositMoney(char * username);//��Ǯ 
void QueryMoney(char * username);//��ѯ 
void ChangePassword();//�޸����� 
void Remittance(char * username);//ת��
 
int main(){
 	Menu_Select();
 	return 0;
}
void Menu_Select(){
 	int select = -1; //�˵�ѡ�� 
 	MenuView_UnLogin(); //�ȵ�¼�ڲ���;
	scanf("%d",&select); //������ѡ�� 
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
	int select = -1; //�˵�ѡ�� 
	MenuView_Login();
	scanf("%d",&select); //������ѡ�� 
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
		InfoTips("���������ڵ���6 С�ڵ���12");
		Menu_Select();
		return;
	}
	if(strcmp(password,password_r) != 0){
		InfoTips("        �������벻һ��      ");
		Menu_Select();
		return ;
	}
	user = get_user(username); 
	if(strlen(user.name) != 0){
		InfoTips("       �û����Ѵ���        ");
		Menu_Select();
		return ;
	}
	reg_user(username,password);
	InfoTips("     ע��ɹ�,�����µ�½    ");
	Menu_Select();
}
void DrawMoney(char * username){
	int select = -1; //�˵�ѡ�� 
	DrawMoneyView();
	scanf("%d",&select); //������ѡ�� 
	if(select == 1){
		if(!hasMoney(username,100)){
			InfoTips("          ����          ");
			OldUserMenu(username);
			return;
		}
		takeMoney(username,100);
	}else if(select == 2){
		if(!hasMoney(username,500)){
			InfoTips("          ����          ");
			OldUserMenu(username);
			return;
		}
		takeMoney(username,500);
	}else if(select == 3){
		if(!hasMoney(username,1000)){
			InfoTips("          ����          ");
			OldUserMenu(username);
			return;
		}
		takeMoney(username,1000);
	}else if(select == 4){
		OldUserMenu(username);
	}
	InfoTips("           ȡ��ɹ�         ");
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
	InfoTips("          ���ɹ���        "); 
	OldUserMenu(username); 
}
void QueryMoney(char * username){
	struct User user;
	int select = -1; //�˵�ѡ�� 
	user = get_user(username);
	QueryMoneyView(user.money);
	scanf("%d",&select); //������ѡ�� 
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
		InfoTips("���������ڵ���6 С�ڵ���12");
		OldUserMenu(username);
		return;
	}
	if(strcmp(newPass,newPass_r) != 0){
		InfoTips("        �������벻һ��      ");
		OldUserMenu(username);
		return ;
	}
	user = login_user(username,oldPass);
	if(user == NULL){
		InfoTips("         ���������!       ");
		OldUserMenu(username);
		return;
	}
	strcpy(user->pass,newPass);
	save_user(*user);
	InfoTips("    �޸ĳɹ�!�����µ�½!    ");
	Menu_Select();
}
void Remittance(char * username){
	char name[50];
	double money = 0.0;
	struct User user2;
	struct User user;
	RemittanceView(name,&money);
	if(!hasMoney(username,money)){
		InfoTips("          ����          ");
		OldUserMenu(username);
		return;
	}
	user2 = get_user(name);
	if(strlen(user2.name) == 0){
		InfoTips("       �û�������        ");
		OldUserMenu(username);
		return ;
	}
	takeMoney(username,money);
	giveMoney(name,money);
	DepositMoneyAnimation();
	InfoTips("         ת�˳ɹ�          ");
	OldUserMenu(username);
} 
void OldUserLogin(){
		cls();
		char name[50];
		char password[50];
		printf("����������˺ţ�");
		scanf("%s",&name);
		printf("������������룺");
		scanf("%s",&password);
		/**�û���½**/
		struct User  * user;
		user = login_user(name,password);
		if(user == NULL){
			InfoTips("        �˺Ż��������      ");
			Menu_Select();
		}else{
			strcpy(name,user->name);
			OldUserMenu(name);
		}
}
