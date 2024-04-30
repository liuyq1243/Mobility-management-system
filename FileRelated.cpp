#include "FileRelated.h"

int WriteToFile(FILE* fp,PERSON persons[],int personsNum){
    for(int i=0;i<personsNum;i++)	
 	{
  		fprintf(fp,"%s %s %d %d %s %d %d",persons[i].IDNumber,persons[i].name,persons[i].age,persons[i].sex,persons[i].address,
                persons[i].lastTime,persons[i].lastResult);
		fprintf(fp,"\n");  		
 	}

    return 1;
}

int ReadFromFile(FILE* fp,PERSON persons[]){
    int i=0;

    while(1){
        int nReadNum=0;
		nReadNum+=fscanf(fp,"%s%s%d%d%s%d%d",&persons[i].IDNumber,&persons[i].name,&persons[i].age,&persons[i].sex,&persons[i].address,&persons[i].lastTime,
                &persons[i].lastResult);
        
        // while(1){
        //     fscanf(fp,"%s",&persons[i].standPlace[persons[i].standNum]);
        //     persons[i].standNum++;
        // }

        if(nReadNum==7)
            i++;
        else{
            break;
        }
	}

    // printf("%s",persons[0].IDNumber);

	return i;//返回读到的学生数 
}

int BackUpToFile(PERSON persons[],int personsNum){
    FILE* fp=NULL;
    
    if(!(fp=fopen(BACKUPNAME,"w"))){
        printf("Cant't create file backup.txt!\n");
        exit(1);
    }

    WriteToFile(fp,persons,personsNum);

    return 1;
}