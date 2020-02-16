/*
	Name: ViewMain 
	Copyright: 台州科技学院
	Author: 吴联爽
	Date: 11/12/19 19:10
	Description: 界面 
*/
void cls(){
	system("cls");
} 
void Header(){
cls();
printfNowTime();
printf("      ※※※※※※ 欢 迎 使 用 PY银行※※※※※※※※      \n");
printf("      ※※※※※校 园 银 行 系 统 ※※※※※※      \n");	
}
void MenuView_UnLogin(){
Header();
printf("      ----------------------------------------      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （1）老用户登录       ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （2）新用户开卡       ★★★      \n");
printf("      ★★★                            ★★★      \n"); 
printf("      ★★★      （3）退    出         ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ----------------------------------------      \n"); 
printf("      请输入你的选项：");
}
void MenuView_Login(){
Header();
printf("      ----------------------------------------      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （1）取       款      ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （2）存       款      ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （3）查       询      ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （4）修 改 密 码      ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （5）转       账      ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （6）退       出      ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ----------------------------------------      \n"); 
printf("      请输入你的选项：");
}
void ErrorInputTips(int index,void (*callfuct)()){
Header();
printf("      ----------------------------------------      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★    请输入1-%d之间的数字     ★★★      \n",index);
printf("      ★★★                            ★★★      \n");
printf("      ★★★     3秒之后跳转到主页面    ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ----------------------------------------      \n"); 
Sleep(3000);
callfuct();
}

void InfoTips(char * tips){
Header();
printf("      ----------------------------------------      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★%s★★★      \n",tips);
printf("      ★★★                            ★★★      \n");
printf("      ★★★     3秒之后跳转到主页面    ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ----------------------------------------      \n"); 
Sleep(3000);
}
void ExitMessageView(){
Header();
printf("      ----------------------------------------      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★           退出成功!        ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★         欢迎下次再来!      ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ----------------------------------------      \n"); 	
system("pause"); 
}
int RegUserView(char * user,char * pass,char * pass_r){
Header();
printf("    -------------------------------------------      \n");
printf("    ****** （1）账号姓名                ******      \n");
printf("                ");
scanf("%s",user);
printf("    ****** （2）请输入你要设置的密码    ******      \n");
printf("                ");
scanf("%s",pass);
printf("    ****** （3）请确认密码              ******      \n");
printf("                ");
scanf("%s",pass_r);
printf("    -------------------------------------------      \n");
} 
void ChangePasswordView(char * oldPass,char * newPass,char * newPass_r){
Header();
printf("      ----------------------------------------      \n");
printf("      ★★★      请输入旧密码          ★★★      \n");
printf("                  ");
scanf("%s",oldPass);
printf("      ★★★      请输入新密码          ★★★      \n");
printf("                  ");
scanf("%s",newPass);
printf("      ★★★      请重新输入新密码      ★★★      \n");
printf("                  ");
scanf("%s",newPass_r);
printf("      ★★★                            ★★★      \n");
printf("      ----------------------------------------      \n");  
} 
void QueryMoneyView(double money){
Header();
printf("      ----------------------------------------      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      余额：%.2f          ★★★      \n",money);
printf("      ★★★                            ★★★      \n");
printf("      ★★★      可以余额：%.2f      ★★★      \n",money);
printf("      ★★★                            ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （1）返 回 菜 单      ★★★      \n");
printf("      ★★★      （2）退       卡      ★★★      \n");
printf("      ----------------------------------------      \n");  	
printf("      请输入你的选项：");
} 
void DepositMoneyView(){
Header();
printf("      ----------------------------------------      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★ 请把现金放入下面的的存款口 ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ----------------------------------------      \n");  	
printf("      存入几张?:");  	
}
void DepositMoneyAnimation(){
int i = 0;
int invter = 300;
for(i = 0;i<=3;i++){
	Header();
	printf("      ----------------------------------------      \n");
	printf("      ★★★                            ★★★      \n");
	printf("      ★★★           处理中 -         ★★★      \n");
	printf("      ★★★                            ★★★      \n");
	printf("      ★★★           请稍后           ★★★      \n");
	printf("      ★★★                            ★★★      \n");
	printf("      ----------------------------------------      \n"); 
	Sleep(invter);
	Header();
	printf("      ----------------------------------------      \n");
	printf("      ★★★                            ★★★      \n");
	printf("      ★★★           处理中 \\         ★★★      \n");
	printf("      ★★★                            ★★★      \n");
	printf("      ★★★           请稍后           ★★★      \n");
	printf("      ★★★                            ★★★      \n");
	printf("      ----------------------------------------      \n"); 
	Sleep(invter);
	Header();
	printf("      ----------------------------------------      \n");
	printf("      ★★★                            ★★★      \n");
	printf("      ★★★           处理中 /         ★★★      \n");
	printf("      ★★★                            ★★★      \n");
	printf("      ★★★           请稍后           ★★★      \n");
	printf("      ★★★                            ★★★      \n");
	printf("      ----------------------------------------      \n"); 
	Sleep(invter);
}
}
void DrawMoneyView(){
Header();
printf("      ----------------------------------------      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （1）取100￥          ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （2）取500￥          ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （3）取1000￥         ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      （4）返 回 菜 单      ★★★      \n");
printf("      ★★★                            ★★★      \n");
printf("      ----------------------------------------      \n"); 
printf("      请输入你的选项："); 
}
void RemittanceView(char * name,double * money){
Header();
printf("      ----------------------------------------      \n");
printf("      ★★★                            ★★★      \n");
printf("      ★★★      请选择要转的账号      ★★★      \n");
printf("                  ");
scanf("%s",name);
printf("      ★★★                            ★★★      \n");
printf("      ★★★      请输入金额            ★★★      \n");
printf("                  ");
scanf("%lf",money);
printf("      ★★★                            ★★★      \n");
printf("      ----------------------------------------      \n");  	
}