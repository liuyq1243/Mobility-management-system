#include "Menu.h"

int main(void)
{
    system("chcp 65001");
    PERSON persons[PERSONNUM];  //用户结构体数组
    int pNum=0; //用户个数

    // system("color 5e"); //终端颜色

    FILE* fp=fopen(FILENAME,"r");
    if(!fp){
        printf("\t\t系统指定数据文件: %s 不存在，需要手工输入数据\n",FILENAME);
        AddPerson(persons,&pNum);
        printf("\t\t已成功添加%d个用户数据.......\n",pNum);
        if(!BackUpToFile(persons,pNum)){
            printf("\t\t创建数据文件: %s 失败，添加的数据没有保存在备份文件中\n",BACKUPNAME);	
        }
    }else{
        pNum=ReadFromFile(fp,persons);
        if(pNum){
            printf("\t\t已成功从数据文件中%s读取了%d个用户的数据.......\n\t\t",FILENAME,pNum);
        }else{
            printf("\t\t数据文件%s没有数据或格式不对，请使用信息管理功能添加数据.......\n\t\t",FILENAME);
        }
    }

    fclose(fp); 

    system("pause");
    LoginMenu(persons,&pNum);

    return 1;
}