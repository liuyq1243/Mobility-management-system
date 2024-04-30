#pragma once
#include "ConstDefine.h"
#include "FileRelated.h"
#include<iostream>

using namespace std;

//信息管理模块

/**
 * @brief 添加一个流入人员
 * 
 * @param persons 人员数组
 * @param personsNum 当前系统中人员数量
 * @return int 返回添加的人数
 */
int AddPerson(PERSON persons[],int* personsNum);

/**
 * @brief 输出当前所有人员信息
 * 
 * @param person 人员数组
 * @param personsNum 当前系统中人员数量
 */
void ShowPeronsInfo(PERSON person[],int personsNum,int from,int to);

/**
 * @brief 删除人员
 * 
 * @param person 人员数组
 * @param personsNum 当前系统中人员数量
 * @return int 是否删除成功  1-成功 0-失败
 */
int DeletePerson(PERSON persons[],int* personsNum);

/**
 * @brief 修改人员信息
 * 
 * @param person 人员数组
 * @param personsNum 当前系统中人员数量
 * @return int 是否修改成功  1-成功 0-失败
 */
int ModifyPerson(PERSON persons[],int* personsNum);