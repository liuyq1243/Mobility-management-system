#include "Query.h"

void QueryByIDNumber(PERSON persons[],int personsNum){
    char number[19];
	int t = 0;
	cout<<"                请输入要查询人员的身份证号："; 
	cin>>number;
	cout<<endl;
	for( int i = 0 ; i < personsNum ; i++ ){
		if( strcmp(number,persons[i].IDNumber)==0 ){
			ShowPeronsInfo(persons,personsNum,i,i+1);
			t = 1;
			break;
		}
	} 
	 if( t == 0 )cout<<"                您输入的身份证号不存在，请重新查询"<<endl;
}

void QueryByName(PERSON persons[],int personsNum){
    vector<string> list;
	for (int i = 0; i < personsNum; i++)
	{
		list.push_back(persons[i].name);
	}
	printf("\n\t\t\t这里是按姓名查找人员信息模块\n");
	string name;
	cout << "\t\t\t请输入要查询人员的姓名：";
	cin >> name;
	int flag=1; 
	for (int i = 0; i < personsNum; i++)
	{
		if (name==list[i])
		{
			flag=0;
			ShowPeronsInfo(persons, personsNum, i, i + 1);
		}
	}
	if(flag)
    cout << "\n\t\t\t没有此姓名的人员，请重新输入！\n";
}