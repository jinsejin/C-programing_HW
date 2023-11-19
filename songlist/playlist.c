#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_list 100

typedef struct{ 
    int no;
    char soname[100];
    char name[20];
}play_list;
typedef struct{ 
    int no;
    char soname[100];
}play_lirics;

void liricslist(play_lirics* lirics[],char* list);
int readlist(play_list* p[],char* list); 
void list(play_list* p[],int n);
int addsong(play_list* p[],int n);
void modisong(play_list* p[],int n);
void savefile(play_list* p[],int n);
void liricsthesong(play_lirics* l[]);

int main(){
    int input = 0;
    int count = 0;
    play_list* pi[MAX_list];
    play_lirics* lirics[MAX_list]; 
    count = readlist(pi,"list.txt"); 
    liricslist(lirics,"listliric.txt");
    while(1){
    printf("input 1(list), 2(add playlist) 3,(modify),4(lyrics) 0,(end))>>");
    scanf("%d",&input);
    if(input == 1){ // 노래리스트 불러 오기,
        list(pi,count);
    }
    else if(input == 2){
        count = addsong(pi,count);
    }
    else if(input == 3){
        modisong(pi,count);
    }
    else if(input == 4){
        liricsthesong(lirics);
    }
    else if(input == 0){
        savefile(pi,count);
        break;
    }
    else{
        printf("잘못 입력, 다시 입력하시오.\n");
    }
    
    }
    return 0;
}
int readlist(play_list* p[],char* list){
    int size =0;
    FILE* fp;
    fp = fopen(list,"r");
    while(!feof(fp)){
        p[size] = (play_list*)malloc(sizeof(play_list));
        int temp = fscanf(fp,"%d %s %s",&p[size]->no,p[size]->soname,p[size]->name);
        if(temp < 3){
            break;
        }
        size++;
    }
    fclose(fp);
    return size;
}
void liricslist(play_lirics* lirics[],char* list){
    FILE* fp;
    fp = fopen(list,"r");
    int i=0;
    while(!feof(fp)){
        lirics[i] = (play_lirics*)malloc(sizeof(play_lirics));
        int temp = fscanf(fp,"%d %s",&lirics[i]->no,lirics[i]->soname);
        if(temp < 2){
            break;
        }
        i++;
    }
}
void list(play_list* p[],int n){
    printf("<< playlist >>\n");
    for(int i=0; i<n; i++){
        printf("%d. %s %s\n",p[i]->no,p[i]->soname,p[i]->name);
    }
    printf("\n");
}
int addsong(play_list* p[],int n){
    play_list* rp = NULL;
    rp = (play_list*)malloc(sizeof(play_list));
    printf("input the name of song >> \n");
    scanf("%s",rp->soname);
    printf("input the singer name >> \n");
    scanf("%s",rp->name);
    p[n] = rp;
    p[n]-> no = n+1;
    return n+1;
}
void modisong(play_list* p[],int n){
    //노래 제목 입력하기
    // 입력한 노래 제목 관련 정보만 출력하기
    // 그리고 수정하기
    int no=0;
    //char name[20];
    play_list* rp;
    rp =(play_list*)malloc(sizeof(play_list));
    printf("what do you want chage the song(input no.) >>");
    scanf("%d",&no);
    if(no == p[no-1]->no){
        printf("no.[%d] song : %s singer : %s\n",p[no-1]->no,p[no-1]->soname,p[no-1]->name);
        printf("input the name of song >>");
        scanf("%s",rp->soname);
        printf("intput name of the singer >> ");
        scanf("%s",rp->name);
        rp->no = no;
        p[no-1] = rp;
    }
    else{
        printf("does not exist the song in playlist\n");
    }
}
void savefile(play_list* p[],int n){
    FILE* fp1;
    fp1 = fopen("list.txt","w");
    for(int i=0; i<n; i++){
        fprintf(fp1,"%d %s %s\n",p[i]->no,p[i]->soname,p[i]->name);
    }
    printf("data of %d'th is saved !!",n);
}
void liricsthesong(play_lirics* l[]){
    FILE* list;
    play_lirics* rp;
    int no = 0;
    int i=0;
    char* name[300];
    char* pname;
    printf("what do you want see the lirics (input no.) >>");
    scanf("%d",&no);

    rp = l[no-1];
    pname = strcat(rp->soname,".txt");
    printf("%s\n",pname);
    list = fopen(pname,"r");

    while(!feof(list)){
        name[i] = (char*)malloc(1000*sizeof(char));
        fgets(name[i],1000,list);
        i++;
    }
    for(int j=0; j<i; i++){
        printf("%s",name[j]);
    }
    fclose(list);
}