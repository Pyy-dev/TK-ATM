/*
	Name: ATMStorage 
	Copyright: 台州科技学院 
	Author: XMAO
	Date: 10/11/19 22:11
	Description: 文件存储及更新 
*/

struct User
{
   char name[50];
   char  pass[50];
   double  money;
};
struct User user(char name_[50],char pass_[50],double money_){
	struct User user1;
	strcpy(user1.name,name_);
	strcpy(user1.pass,pass_);
	user1.money = money_;
	return user1;
};
int create_user(struct User user){
	FILE *fp;
	char dir[100] = "data/";
	fp=fopen(strcat(strcat(dir,user.name),".dat"),"wb");
	fwrite(&user,sizeof(user),1,fp); 
	fclose(fp);
}
int update_user(struct User user){
	return create_user(user);
}
struct User get_user(char *name){
	struct User user1;
	char dir[100] = "data/";
	FILE *fp;
	fp=fopen(strcat(strcat(dir,name),".dat"),"rb");
	
	if(fp == NULL ){
		strcpy(user1.name,"");
		return user1;
	}
	
	fread(&user1,sizeof(user1),1,fp); 
	fclose(fp);
	return user1;
};


