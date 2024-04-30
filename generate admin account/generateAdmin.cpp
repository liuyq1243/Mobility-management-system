#include<stdio.h>
#include<stdlib.h>
#include "base64.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAXLEN 100

int main(void)
{
	char base64_e[MAXLEN]={0},base64_d[MAXLEN]={0};
	
    FILE* fp=NULL;
    if(!(fp=fopen("../accountInfo.dat","w"))){
        printf("Cant'open file accountInfo.dat\n");
        exit(1);
    }

    char userAccount[MAXLEN],pwd[MAXLEN];
    printf("User account: ");
    scanf("%s",userAccount);
    getchar();
    int len=0;
	base64_encode(userAccount,(int)strlen(userAccount),base64_e,&len);
	fprintf(fp,"%s ",base64_e);

    //decode测试
    // base64_decode(base64_e,(int)strlen(base64_e),base64_d,&len);
    // printf("```%s```\n",base64_d);
	
    printf("Password: ");
    scanf("%s",pwd);
    getchar();
	base64_encode(pwd,(int)strlen(pwd),base64_e,&len);
	fprintf(fp,"%s",base64_e);

    //decode测试
    // base64_decode(base64_e,(int)strlen(base64_e),base64_d,&len);
    // printf("```%s```\n",base64_d);

    fclose(fp);

    printf("generate admin account successfully!!\n");
	
	system("pause");

    return 0;
}