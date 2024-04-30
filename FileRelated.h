#pragma once
#include "ConstDefine.h"

//文件操作

/**
 * @brief 将当前人员信息写入fp所指向的文件
 * 
 * @param fp 文件指针
 * @param persons 人员数组
 * @param personsNum 系统当前人员人数
 * @return int 写入是否成功 1-成功 0-失败
 */
int WriteToFile(FILE* fp,PERSON persons[],int personsNum);

/**
 * @brief 从fp所指向的文件中读入数据到persons数组中
 * 
 * @param fp 文件指针
 * @param persons 人员数组
 * @return int 返回读入结构体中的人员数
 */
int ReadFromFile(FILE* fp,PERSON persons[]);

/**
 * @brief 备份当前系统数据到备份文件中
 * 
 * @param persons 人员数组
 * @param personsNum 系统当前人员数量
 * @return int 备份成功-1 失败-0
 */
int BackUpToFile(PERSON persons[],int personsNum);