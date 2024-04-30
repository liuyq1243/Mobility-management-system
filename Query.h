#pragma once
#include "ConstDefine.h"
#include "InfoManage.h"
#include<iostream>
#include<vector>

using namespace std;

//查询相关

/**
 * @brief 通过身份证号查询
 * 
 * @param persons 人员数组
 * @param personsNum 人员数量
 */
void QueryByIDNumber(PERSON persons[],int personsNum);

/**
 * @brief 通过姓名查询 可能有多条结果
 * 
 * @param persons 人员数组
 * @param personsNum 人员数量
 */
void QueryByName(PERSON persons[],int personsNum);