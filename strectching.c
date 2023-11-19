#include <stdio.h>
 #include <string.h>
 #define MAX_LAN 256
 int main(){
    
    char str[MAX_LAN] ={ 0 };
    char strect[MAX_LAN];
    //int j=0;
    printf("Input text: ");
    fgets(str,MAX_LAN,stdin);
    printf("str => %s",str);
    if(str[strlen(str)-1] =='\n')
        str[strlen(str)-1] ='\0';
    int count = strlen(str);
    printf("strlen : %d/",count);

   char blank[MAX_LAN] ={ 0 };
   int n = 2;
   int p=count+(n*(count-2));
   for(int i=0; i<n; i++){ //make blank string to repeat n counts 
        blank[i] = ' ';
        if(i==n-1){
            blank[n+1] ='\0';
        }
    }  
    printf("%s",blank);
    int i=0;
    for(i=0; i<count; i++)
    {   if(i==count-1){ 
            strect[p+1] = str[i];
            strcat(strect,blank);
            strect[p+n] ='\0';
            break;
        }
        else{   
            strect[i+(n*i)] = str[i];
            strect[i+(n*i)+1] = '\0';
            strcat(strect,blank); 
        }
    }
    printf("str => %s",strect);
    return 0;
}
/*if(i==count){ 
            strect[p] = str[i];
            strcat(strect,blank);
            strect[p+n] ='\0';
            break;
        }        
        else{*/