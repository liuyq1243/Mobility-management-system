#include "Analyse.h"

void swap(PERSON* person1,PERSON* person2){
    PERSON tmp;
    tmp=*person1;
    *person1=*person2;
    *person2=tmp;
}

void SortOnIDNum(PERSON persons[],int personsNum){
    printf("\n\t\t\t这里是按身份证号升序排序模块\n"); 
		//待你添加代码 5
		for (int i = 1; i < personsNum; i++)
            for (int j = i - 1; j >= 0 && strcmp(persons[j].IDNumber,persons[j+1].IDNumber)>0; j--)
                swap(&persons[j], &persons[j + 1]);
    ShowPeronsInfo(persons,personsNum,0,personsNum);
}

void GroupByResult(PERSON persons[],int personsNum){
    vector<PERSON> pos; //核酸阳性
    vector<PERSON> nega;    //核酸阴性

    for(int i=0;i<personsNum;i++){
        if(persons[i].lastResult==0){   //阴性
            nega.push_back(persons[i]);
        }else{
            pos.push_back(persons[i]);
        }
    }

    printf("=============核酸阳性======================\n");
    while(!pos.empty()){
        PERSON tmp=pos.back();
        pos.pop_back();
        printf("%s %s\n",tmp.IDNumber,tmp.name);
    }
    printf("=============核酸阴性======================\n");
    while(!nega.empty()){
        PERSON tmp=nega.back();
        nega.pop_back();
        printf("%s %s\n",tmp.IDNumber,tmp.name);
    }
    printf("==========================================\n");
}