#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STUDENT 512

char FILE_NAME[80] ={"name"};
char ID[MAX_STUDENT][16] ={ 0 };
char first_name[MAX_STUDENT][80] ={ 0 };
char last_name[MAX_STUDENT][80] ={ 0 };
char tel[MAX_STUDENT][34] ={ 0 };
int n =0;
int main (void)
{
    int ret;

    FILE* fp = fopen("name","w");
    if(fp==NULL){
        printf("Failed to open file %s\n", FILE_NAME);
        exit(-1);

    }
    for(n=0; ret !=0; n++){
        ret = fscanf(fp," %s %s %s %s ", ID[n], first_name[n],last_name[n],tel[n]);
        if(ret == EOF) break;
    }
    for(int i=0; i<n;i++)
        printf("%s) %s %s %s\n",ID[i], first_name[i],last_name[i],tel[i]);

    fclose(fp);

    char target_name[64] ={0 };
    printf("Input first name : ");
    scanf("%s", target_name);

    int p=0;
    for(p=0; p< n; p++){
      //  if(first_name[p] == target_name) // compares addresses(wrong)
        if(strcmp(first_name[p],target_name)== 0)
            break;
    }

    if(p==n)
        printf("Falied to find %s\n",target_name);
    else
        printf("phone number of %s is %s\n",target_name, tel[p]);
    
return 0;
}   
/*
209123 James Bond 010-1234-5678
209124 Bruce Wayne 010-1234-1234
209125 Peter Parker 010-1234-1111
209126 Clark Kent 010-1234-0000
*/
/* 
    trcmp(str1, str2): returns 0 if str1 and str2 have the same contents
                        returns a negative number if str1 precedes str2 (str1 < str2)
                        returns a positive number if str2 precedes str1 (str1 > str2)
*/