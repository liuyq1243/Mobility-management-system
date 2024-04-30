#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>

#define STRINGLEN 300    //字符串最长长度
#define PERSONNUM 100   //最大人数
#define MAXPLACE 10 //十四天内存储最多驻留地址
#define FILENAME "userinfo.txt" //数据文件名
#define BACKUPNAME "backup.txt" //备份文件名

//人员结构体定义
typedef struct{
    //基本信息
    char IDNumber[19];  //18位身份证号
    char name[STRINGLEN];   //姓名
    int age;    //年龄
    int sex;    //性别  0-woman 1-man
    char address[STRINGLEN];    //居住地址
    //疫情防控信息
    time_t lastTime;    //最近一次核酸时间
    int lastResult; //最近一次核酸结果  0-阴性 1-阳性
}PERSON;