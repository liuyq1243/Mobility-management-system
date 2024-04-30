#include "InfoManage.h"

int AddPerson(PERSON persons[],int* personsNum){
    int num_person = 0;
	
	FILE* fp=fopen(FILENAME,"w+");
    if(!fp){
        printf("AddPerson:Can't open file %s\n",FILENAME);
    }
	
	cout<<"                请输入添加的人员人数：";
	cin>>num_person;
	cout<<endl;

    for(int i  = 0 ; i < num_person ; i++ ){
		printf("                请输入第 %d 个人员身份证号:",*personsNum + i + 1);
		cin>>persons[ *personsNum + i ].IDNumber;
		persons[ *personsNum + i ].IDNumber[19]='\0';
		cout<<endl;
		printf("                姓名:");
		cin>>persons[ *personsNum + i ].name;
		cout<<endl;
		printf("                年龄:");
		cin>>persons[ *personsNum + i ].age;
		cout<<endl;
		printf("                性别（1-男性 0-女性）:");
		cin>>persons[ *personsNum + i ].sex;
		cout<<endl;
		printf("                居住地址:");
		cin>>persons[ *personsNum + i ].address;
        // printf("%s",persons[ *personsNum + i ].address);
		cout<<endl;
        printf("                最后一次核酸时间:");
		cin>>persons[ *personsNum + i ].lastTime;
		cout<<endl;
        printf("                最后一次核酸结果（0-阴性 1-阳性）:");
		cin>>persons[ *personsNum + i ].lastResult;
		cout<<endl;
	} 
	int now_num = num_person + *personsNum;//添加完用户之后总数目；
	*personsNum = now_num;
	
	WriteToFile(fp,persons,now_num);
	
	ShowPeronsInfo(persons,*personsNum,0,*personsNum);
	
    fclose(fp);

 	return num_person;
}

void ShowPeronsInfo(PERSON person[],int personsNum,int from,int to){
    // printf("%d %d %d %s\n",personsNum,from,to,person[0].IDNumber);
    cout<<"身份证号           姓名    年龄  性别      居住地址      最后一次核酸时间  最后一次核酸结果"<<endl;	
	cout<<"============================================================================================="<<endl;
    for(int i = from ; i < to ; i++ ){
        // printf("%s",person[0].IDNumber);
		printf("%-18s  %-6s    %-6d  %-5s     %-20s%-14d%+16s",person[i].IDNumber,person[i].name,
            person[i].age,person[i].sex==0?"女":"男",person[i].address,person[i].lastTime,person[i].lastResult==0?"阴性":"阳性");
        // for(int j=0;j<person[i].standNum;j++){
        //     printf("%s ",person[i].standPlace[j]);
        // }
        printf("\n");
	}
	cout<<"============================================================================================="<<endl; 
}

int DeletePerson(PERSON persons[],int* personsNum){
    ShowPeronsInfo(persons,*personsNum,0,*personsNum);
    cout<<"                请输入要删除的人员身份证号:";

    char IDNumber[19];
	scanf("%s",IDNumber);//输入学号;
    // printf("%s\n",IDNumber);
	
	int t = 0;
	
	for(int i = 0 ; i < *personsNum ; i ++  ){
		if( strcmp(IDNumber,persons[i].IDNumber)==0 ){
			t = 1;
			for(int j = i + 1 ; j < *personsNum ; j ++ ){
				persons[ j - 1 ] = persons[j];	 
			}
			int tmp = *personsNum;
			*personsNum = tmp - 1; 
			FILE* fp1=fopen(FILENAME,"w");
			WriteToFile(fp1,persons,*personsNum);
			fclose(fp1);
			printf("                ......已删除身份证号位%d的用户数据......\n",IDNumber);
			break;
		}
		 
	}
	if(t == 0 )printf("                 没有找到您输的身份证号，请输入正确的身份证号\n",IDNumber);
	ShowPeronsInfo(persons,*personsNum,0,*personsNum);		
	
	return 1;
}

int ModifyPerson(PERSON persons[],int* personsNum){
    ShowPeronsInfo(persons,*personsNum,0,*personsNum);

    cout<<"                请输入要修改的用户身份证号:";
 	
 	char* number;
	cin>>number;
	int t = 0;
	for(int i = 0 ; i < *personsNum ; i++ ){
		if( strcmp(number,persons[i].IDNumber)==0 ){
			printf("										   			\n");
            printf("     			************************************\n");
            printf("     			*         0.居住地址                *\n");
            printf("     			*         1.年龄                    *\n");
            printf("     			*         2.最后一次核酸结果         *\n");
            printf("     			************************************\n");
            printf("                请选择要修改的数据(press 0.1.2):");
            int c = 0;
            cin>>c;
            switch(c){
            	case 0:
            	cout<<"                请输入修改后的居住地址:";
				cin>>persons[i].address;	
				cout<<endl;
            	break;	
            	
				case 1:
            	cout<<"                请输入修改后的年龄:";
				cin>>persons[i].age;	
				cout<<endl;
            	break;	
            	
            	case 2:
            	cout<<"                请输入修改后的最后一次核酸结果（0-阴性 1-阳性）:";
				cin>>persons[i].lastResult;	
				cout<<endl;
            	break;
            	
            	default:
            		cout<<"                ，没有您输的数据类别，请输入正确的类别"<<endl;
			}
			FILE* fp=fopen(FILENAME,"w");
			WriteToFile(fp,persons,*personsNum);

			t = 1;
			break;
		}
	}
	
 	if( t == 0 )cout<<"                 没有您输的身份证号，请输入正确的身份证号"<<endl;
 	
 	ShowPeronsInfo(persons,*personsNum,0,*personsNum);
 
	return 1;
}