#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME "studentInfo.txt"
#define MAX_STUDENT 256
typedef struct{
    char ID[16];
    char first_name[64];
    char last_name[64];
    char tell[20];
}student;
 //TO DO: declare an array of Student
student* students[MAX_STUDENT];  // the i-th student: student[i]
int no_student = 0;

int main(){
    FILE* fp;
    fp = fopne(FILE_NAME,"r");
    if(fp == NULL){
        printf("Failed to open %s.\n", FILE_NAME);
        exit(-1);
    }
    while(1){
        //allocate a sturcture variable for the new entry
        students[no_student]=(student*)malloc(sizeof(student));
        int temp = fscanf(fp,"%s %s %s %s",students[no_student]->ID,students[no_student]->first_name,students[no_student]->last_name,students[no_student]->tell);
        if(temp == EOF){
            break;
        }
        no_student++;
    }
      fclose(fp);
    for(int i=0; i<no_student;i++ ){
         printf("%s %s %s %s\n", students[i]->ID, students[i]->first_name,students[i]->last_name,students[i]->tell);
    }
    for(int i=0; i<no_student; i++){
        free(students[i]);
        students[i] = NULL;
    }
    return 0;
}