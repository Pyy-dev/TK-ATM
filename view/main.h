/*
	Name: ViewMain 
	Copyright: ̨�ݿƼ�ѧԺ
	Author: ����ˬ
	Date: 11/12/19 19:10
	Description: ���� 
*/
void cls(){
	system("cls");
} 
void Header(){
cls();
printfNowTime();
printf("      ������������ �� ӭ ʹ �� PY���С���������������      \n");
printf("      ����������У ԰ �� �� ϵ ͳ ������������      \n");	
}
void MenuView_UnLogin(){
Header();
printf("      ----------------------------------------      \n");
printf("      ����                            ����      \n");
printf("      ����      ��1�����û���¼       ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��2�����û�����       ����      \n");
printf("      ����                            ����      \n"); 
printf("      ����      ��3����    ��         ����      \n");
printf("      ����                            ����      \n");
printf("      ----------------------------------------      \n"); 
printf("      ���������ѡ�");
}
void MenuView_Login(){
Header();
printf("      ----------------------------------------      \n");
printf("      ����                            ����      \n");
printf("      ����      ��1��ȡ       ��      ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��2����       ��      ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��3����       ѯ      ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��4���� �� �� ��      ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��5��ת       ��      ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��6����       ��      ����      \n");
printf("      ����                            ����      \n");
printf("      ----------------------------------------      \n"); 
printf("      ���������ѡ�");
}
void ErrorInputTips(int index,void (*callfuct)()){
Header();
printf("      ----------------------------------------      \n");
printf("      ����                            ����      \n");
printf("      ����    ������1-%d֮�������     ����      \n",index);
printf("      ����                            ����      \n");
printf("      ����     3��֮����ת����ҳ��    ����      \n");
printf("      ����                            ����      \n");
printf("      ----------------------------------------      \n"); 
Sleep(3000);
callfuct();
}

void InfoTips(char * tips){
Header();
printf("      ----------------------------------------      \n");
printf("      ����                            ����      \n");
printf("      ����%s����      \n",tips);
printf("      ����                            ����      \n");
printf("      ����     3��֮����ת����ҳ��    ����      \n");
printf("      ����                            ����      \n");
printf("      ----------------------------------------      \n"); 
Sleep(3000);
}
void ExitMessageView(){
Header();
printf("      ----------------------------------------      \n");
printf("      ����                            ����      \n");
printf("      ����           �˳��ɹ�!        ����      \n");
printf("      ����                            ����      \n");
printf("      ����         ��ӭ�´�����!      ����      \n");
printf("      ����                            ����      \n");
printf("      ----------------------------------------      \n"); 	
system("pause"); 
}
int RegUserView(char * user,char * pass,char * pass_r){
Header();
printf("    -------------------------------------------      \n");
printf("    ****** ��1���˺�����                ******      \n");
printf("                ");
scanf("%s",user);
printf("    ****** ��2����������Ҫ���õ�����    ******      \n");
printf("                ");
scanf("%s",pass);
printf("    ****** ��3����ȷ������              ******      \n");
printf("                ");
scanf("%s",pass_r);
printf("    -------------------------------------------      \n");
} 
void ChangePasswordView(char * oldPass,char * newPass,char * newPass_r){
Header();
printf("      ----------------------------------------      \n");
printf("      ����      �����������          ����      \n");
printf("                  ");
scanf("%s",oldPass);
printf("      ����      ������������          ����      \n");
printf("                  ");
scanf("%s",newPass);
printf("      ����      ����������������      ����      \n");
printf("                  ");
scanf("%s",newPass_r);
printf("      ����                            ����      \n");
printf("      ----------------------------------------      \n");  
} 
void QueryMoneyView(double money){
Header();
printf("      ----------------------------------------      \n");
printf("      ����                            ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��%.2f          ����      \n",money);
printf("      ����                            ����      \n");
printf("      ����      ������%.2f      ����      \n",money);
printf("      ����                            ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��1���� �� �� ��      ����      \n");
printf("      ����      ��2����       ��      ����      \n");
printf("      ----------------------------------------      \n");  	
printf("      ���������ѡ�");
} 
void DepositMoneyView(){
Header();
printf("      ----------------------------------------      \n");
printf("      ����                            ����      \n");
printf("      ���� ����ֽ��������ĵĴ��� ����      \n");
printf("      ����                            ����      \n");
printf("      ----------------------------------------      \n");  	
printf("      ���뼸��?:");  	
}
void DepositMoneyAnimation(){
int i = 0;
int invter = 300;
for(i = 0;i<=3;i++){
	Header();
	printf("      ----------------------------------------      \n");
	printf("      ����                            ����      \n");
	printf("      ����           ������ -         ����      \n");
	printf("      ����                            ����      \n");
	printf("      ����           ���Ժ�           ����      \n");
	printf("      ����                            ����      \n");
	printf("      ----------------------------------------      \n"); 
	Sleep(invter);
	Header();
	printf("      ----------------------------------------      \n");
	printf("      ����                            ����      \n");
	printf("      ����           ������ \\         ����      \n");
	printf("      ����                            ����      \n");
	printf("      ����           ���Ժ�           ����      \n");
	printf("      ����                            ����      \n");
	printf("      ----------------------------------------      \n"); 
	Sleep(invter);
	Header();
	printf("      ----------------------------------------      \n");
	printf("      ����                            ����      \n");
	printf("      ����           ������ /         ����      \n");
	printf("      ����                            ����      \n");
	printf("      ����           ���Ժ�           ����      \n");
	printf("      ����                            ����      \n");
	printf("      ----------------------------------------      \n"); 
	Sleep(invter);
}
}
void DrawMoneyView(){
Header();
printf("      ----------------------------------------      \n");
printf("      ����                            ����      \n");
printf("      ����      ��1��ȡ100��          ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��2��ȡ500��          ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��3��ȡ1000��         ����      \n");
printf("      ����                            ����      \n");
printf("      ����      ��4���� �� �� ��      ����      \n");
printf("      ����                            ����      \n");
printf("      ----------------------------------------      \n"); 
printf("      ���������ѡ�"); 
}
void RemittanceView(char * name,double * money){
Header();
printf("      ----------------------------------------      \n");
printf("      ����                            ����      \n");
printf("      ����      ��ѡ��Ҫת���˺�      ����      \n");
printf("                  ");
scanf("%s",name);
printf("      ����                            ����      \n");
printf("      ����      ��������            ����      \n");
printf("                  ");
scanf("%lf",money);
printf("      ����                            ����      \n");
printf("      ----------------------------------------      \n");  	
}