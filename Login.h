#pragma once
#include "ConstDefine.h"
#include "Menu.h"
#include "base64.h"
#include<windows.h>
#include<iostream>

#define ACCOUNTFILE "accountInfo.dat"

using namespace std;

void gotoxy(int x,int y);

/**
 * @brief 登录面板
 * 
 * @return void 
 */
void LoginMenu(PERSON persons[],int* personNum);

/**
 * @brief 传入用户名和密码进行登录，账号密码在文件中验证
 * 
 * @param username 用户名
 * @param pwd 密码
 * @return int 
 */
int Login(char* accountNum,char* pwd,PERSON persons[],int* pNum);