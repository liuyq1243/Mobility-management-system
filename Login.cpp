#include "Login.h"

void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void LoginMenu(PERSON persons[],int* personNum){
    char accountNum[STRINGLEN];
    char pwd[STRINGLEN];
	while(1){
        system("CLS");//清空控制台内容;
        printf("\t\t   ----------------------------  \n");
        printf("\t\t|    流动人员管理系统           |\n");
        printf("\t\t|                               |\n");
        printf("\t\t|     账号：—————          |\n");
        printf("\t\t|     密码：—————          |\n");
        printf("\t\t|                               |\n");
        printf("\t\t|             登录              |\n");
        printf("\t\t|                               |\n");
        printf("\t\t   ----------------------------  \n"); 
        gotoxy(28,3);
        cin>>accountNum;
        gotoxy(28,4);
        cin>>pwd;
        int ret=Login(accountNum,pwd,persons,personNum);
    }
}

int Login(char* accountNum,char* pwd,PERSON persons[],int* pNum){
    FILE* fp=NULL;
    if(!(fp=fopen(ACCOUNTFILE,"rb"))){
        printf("Login:Can't open file %s\n",ACCOUNTFILE);
        exit(1);
    }

    char base64_e[STRINGLEN];
    char true_account[STRINGLEN],true_pwd[STRINGLEN];
    //user account解密
    fscanf(fp,"%s",base64_e);
    int len=0;
    base64_decode(base64_e,(int)strlen(base64_e),true_account,&len);
    //password 解密
    fscanf(fp,"%s",base64_e);
    base64_decode(base64_e,(int)strlen(base64_e),true_pwd,&len);

    int flag=0; //登录状态 0-登录失败 1-登录成功
    if(strcmp(accountNum,true_account)==0){
        if(strcmp(true_pwd,pwd)==0){
            flag=1;
        }
    }

    // printf("%s %s",true_account,true_pwd);

    if(flag){
        gotoxy(25,6);
        printf("Login successfully!\n");
        system("pause>0");
        MainMenu(persons,pNum);
    }else{
        gotoxy(18,6);
        printf("Useraccount or password error!\n");
        system("pause>0");
        return 0;
    }
}
