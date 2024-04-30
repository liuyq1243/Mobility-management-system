#include "Menu.h"

void MainMenu(PERSON persons[],int* pNum){
    int nMainchoose;
	//主菜单无限循环 
	while(1)
	{
		system("CLS"); //系统屏幕清空 
		//输出菜单主界面 
		printf("\t\t   ------------------------  \n");
		printf("\t\t|      流动人口管理系统      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  1.信息显示   2.信息管理   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  3.账户管理   4.条件查询   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  5.数据分析   0.退出系统   |\n");
		printf("\t\t   ------------------------  \n");
		//根据宏定义的文件名和学生数额显示 
		printf("\n\t数据文件%s中目前共有%d名用户 \n\n",FILENAME,*pNum);
		//请用户输入选择的数字 
		printf("\t\t   请选择功能序号(0~5):");
		//用户根据界面提示输入数字 
	    scanf("%d",&nMainchoose);	
		//根据用户输入的数字看如何行动					
		switch(nMainchoose)
		{
		   //信息显示 
			case 1: printf("\n");
			        //调用输出学生信息函数 
				    ShowPeronsInfo(persons,*pNum,0,*pNum);	//转到输出显示函数 
				    system("PAUSE");
			        break;
			//转到二级菜单：信息管理模块菜单选项显示 
			case 2: ManageMenu(persons,pNum);
					break;
			//转到二级菜单：用户管理模块菜单选项显示
			case 3:AdminManage(persons,pNum);	
					break;
			//转到二级菜单：条件查询模块菜单选项显示
			case 4:QueryMenu(persons,pNum);
					break;
			case 5:AnalyMenu(persons,pNum);
					break;
			//用户选择退出		
			case 0: printf("\n\n\t\t感谢使用我们的软件，欢迎下次再来！") ;
			        exit(0);
					break; 
			//用户选择有误 
			default:printf("选择有误，请重选！\n");
		}//switch结束 
	}//while(1)函数结束 
}

void ManageMenu(PERSON persons[],int* pNum){
    int nManageChoose;
	while(1)
	{   system("CLS");
		printf("\t\t------------------------------\n");
		printf("\t\t|********信息管理模块********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        1.增加用户信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        2.删除用户信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        3.修改用户信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        0.返回上级菜单      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t   ------------------------  \n");
		printf("\n\t数据文件%s中目前共有%d名用户 \n\n",FILENAME,*pNum);
		printf("\t\t   请选择功能序号(0~3):");
		//读入用户选择 
		scanf("%d",&nManageChoose);
		switch(nManageChoose)
		{
			case 1:AddPerson(persons,pNum);//转到增加学生信息函数 
			       //OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//输出给用户看一下 
			       	system("PAUSE");
				   break;
			case 2:DeletePerson(persons,pNum);//转到删除学生信息函数
			       //OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//输出给用户看一下 
			       	system("PAUSE");
				   break;
			case 3:ModifyPerson(persons,pNum);//转到修改学生信息函数
			       //OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//输出给用户看一下 
			       	system("PAUSE");
					break;
			case 0: MainMenu(persons,pNum);			//返回一级主菜单函数 
			        break;
					
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 */
	}//while(1)结束 
}

void QueryMenu(PERSON persons[],int* pNum){
    int nQueryChoose;
	while(1)
	{
		system("CLS");
		printf("\t\t---------------------------------------\n");
		printf("\t\t|*************信息查询模块************|\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         1.根据身份证号查询信息      |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         2.根据姓名查询信息          |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         0.返回上级菜单              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t---------------------------------------\n");
		printf("\t\t                            \n");
		printf("\t\t   请选择功能序号(0~2):");
		
		
		scanf("%d",&nQueryChoose);
		
		switch(nQueryChoose)
		{
			case 1: QueryByIDNumber(persons,*pNum);	//按学号查询学生信息 
			        system("PAUSE");
					break;
			case 2: QueryByName(persons,*pNum); //按姓名查询学生信息 
			        system("PAUSE");
					break;
			case 0: MainMenu(persons,pNum); 	//返回一级主菜单选项 
					break;
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 
		
	}//while结束 
}

void AdminManage(PERSON persons[],int* pNum){
	int nChoose;
	while(1)
	{
		system("CLS");
		printf("\t\t---------------------------------------\n");
		printf("\t\t|*************账户管理模块************|\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         1.修改账户密码              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         0.返回上级菜单              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t---------------------------------------\n");
		printf("\t\t                            \n");
		printf("\t\t   请选择功能序号(0~1):");
		
		
		scanf("%d",&nChoose);
		
		switch(nChoose)
		{
			case 1: ModifyPwd();	//修改登录用户密码
			        system("PAUSE");
					break;
			case 0: MainMenu(persons,pNum); 	//返回一级主菜单选项 
					break;
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 
		
	}//while结束 

	system("pause");
}

void CommunityManage(PERSON persons[],int* pNum){
	int nChoose;
	while(1)
	{
		system("CLS");
		printf("\t\t---------------------------------------\n");
		printf("\t\t|*************社区管理模块************|\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         1.              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         0.返回上级菜单              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t---------------------------------------\n");
		printf("\t\t                            \n");
		printf("\t\t   请选择功能序号(0~1):");
		
		
		scanf("%d",&nChoose);
		
		switch(nChoose)
		{
			case 1: ModifyPwd();	//修改登录用户密码
			        system("PAUSE");
					break;
			case 0: MainMenu(persons,pNum); 	//返回一级主菜单选项 
					break;
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 
		
	}//while结束 

	system("pause");
}


void AnalyMenu(PERSON persons[],int* pNum){
	int nChoose;
	while(1)
	{
		system("CLS");
		printf("\t\t---------------------------------------\n");
		printf("\t\t|*************数据分析模块************|\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         1.身份证号排序              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         2.核酸结果分组              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         0.返回上级菜单              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t---------------------------------------\n");
		printf("\t\t                            \n");
		printf("\t\t   请选择功能序号(0~2):");
		
		scanf("%d",&nChoose);
		
		switch(nChoose)
		{
			case 1: SortOnIDNum(persons,*pNum);	
			        system("PAUSE");
					break;
			case 2: GroupByResult(persons,*pNum);	
			        system("PAUSE");
					break;
			case 0: MainMenu(persons,pNum); 	//返回一级主菜单选项 
					break;
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 
		
	}//while结束 

	system("pause");
}