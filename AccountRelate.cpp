#include "AccountRelate.h"

char *trim(char *str)
{
        char *p = str;
        char *p1;
        if(p)
        {
                p1 = p + strlen(str) - 1;
                while(*p && isspace(*p)) p++;
                while(p1 > p && isspace(*p1)) *p1-- = '/0';
        }
        return p;
}

int ModifyPwd(){
    int len=0;
    char old_pwd[STRINGLEN];
    char new_pwd[STRINGLEN];
    printf("请输入旧密码: ");
    scanf("%s",old_pwd);
    // printf("%s",old_pwd);s
    getchar();

    FILE* fp=NULL;
    if(!(fp=fopen("accountInfo.dat","r+"))){
        printf("Modify:Can't open file accountInfp.dat\n");
    }

    char base64_e_account[STRINGLEN],base64_e_pwd[STRINGLEN];
    fscanf(fp,"%s %s",base64_e_account,base64_e_pwd);
    // printf("%s %s\n",base64_e_account,base64_e_pwd);

    // char username[]="admin";
    // char base64_username[STRINGLEN];
    // base64_encode(username,(int)strlen(username),base64_username,&len);
    char base64_old_pwd[STRINGLEN]={'\0'};
    base64_encode(old_pwd,(int)strlen(old_pwd),base64_old_pwd,&len);

    // printf("```%s %s```\n",base64_e_pwd,base64_old_pwd);
    if(strcmp(trim(base64_e_pwd),trim(base64_old_pwd))==0){
        printf("请输入新密码: ");
        scanf("%s",new_pwd);
        getchar();

        char base64_e_new_pwd[STRINGLEN]={'\0'};
        base64_encode(new_pwd,(int)strlen(new_pwd),base64_e_new_pwd,&len);
        fseek(fp,0,SEEK_SET);
        fprintf(fp,"%s %s",base64_e_account,base64_e_new_pwd);

        printf("update password successfully!\n");
        fclose(fp);
        // system("pause");
        return 1;
    }else{
        printf("旧密码错误！\n");

        fclose(fp);
        return 0;
    }
}