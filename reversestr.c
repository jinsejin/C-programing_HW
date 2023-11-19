 
 #include <stdio.h>
 #include <string.h>
 #define MAX_LAN 256
 int main(){
    
    char str[MAX_LAN] ={ 0 };
    char reverse[MAX_LAN];
    int j=0;
    printf("Input text: ");
    fgets(str,MAX_LAN,stdin);
    printf("str => %s",str);
    if(str[strlen(str)-1] =='\n')
        str[strlen(str)-1] ='\0';
    int l = strlen(str);
    printf("strlen : %d/",l);
    for(int i=l; i>=0;i--){ // 뒤에 있는 걸 앞으로 가져오는 작업을 문자열의 첫번째까지 해준다. 
        reverse[j] = str[i-1];
        if(i==0){
            str[j+1] = '\0';
            break;
        }
        j++;  
    }
    for(int i=0; i<l; i++){
        str[i] = reverse[i];
        if(i==l-1){
            str[i+1] = '\0';
            break;
        }
    }
    printf("str => %s",str);
    return 0;
}