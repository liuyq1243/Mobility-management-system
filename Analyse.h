#pragma once
#include "ConstDefine.h"
#include "InfoManage.h"
#include<vector>

//统计分析模块

/**
 * @brief 通过身份证号排序
 * 
 * @param persons 人员数组
 * @param personsNum 人员数量
 */
void SortOnIDNum(PERSON persons[],int personsNum);

/**
 * @brief 通过核算结果分组
 * 
 * @param persons 人员数组
 * @param personsNum 人员数量
 */
void GroupByResult(PERSON persons[],int personsNum);