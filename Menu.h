#pragma once
#include "ConstDefine.h"
#include "Analyse.h"
#include "AccountRelate.h"
#include "FileRelated.h"
#include "InfoManage.h"
#include "Login.h"
#include "Query.h"

//菜单
/**
 * @brief 一级菜单  主菜单
 * 
 * @param persons 用户数组
 * @param pNum 用户数量
 */
void MainMenu(PERSON persons[],int* pNum);
/**
 * @brief 二级菜单  信息管理
 * 
 * @param persons 用户数组
 * @param pNum 用户数量
 */

void ManageMenu(PERSON persons[],int* pNum);

/**
 * @brief 二级菜单  条件查询
 * 
 * @param persons 用户数组
 * @param pNum 用户数量
 */
void QueryMenu(PERSON persons[],int* pNum);

/**
 * @brief 二级菜单  管理员管理
 * 
 * @param persons 用户数组
 * @param pNum 用户数量
 */
void AdminManage(PERSON persons[],int* pNum);

/**
 * @brief 社区管理
 * 
 * @param persons 
 * @param pNum 
 */
void CommunityManage(PERSON persons[],int* pNum);

/**
 * @brief 数据分析
 * 
 * @param persons 
 * @param pNum 
 */
void AnalyMenu(PERSON persons[],int* pNum);