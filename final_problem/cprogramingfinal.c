/*
학번과 이름 기입 21800712 진세진
아너코드 선언문 기입
나 진세진은 하나님과 사람 앞에서 정직하고 성실하게 코딩 테스트를 수행하겠습니다.
*/
/*
전체적인 정리
우리나라 지역과 그에 대한 데이터를 6개의 기능과 내가 추가한 1가지의 기능을 가진 crud시스템을 만드는 코드입니다.
struct st_data 일단 구조체 변수를 있고. 메인에서 그 구조체 함수를 포인터 배열 변수를 메인에 만들어서 data.txt 파일안에있는 정보를 입력을 받아 구조체 포인터 배열 변수에 집어넣어주면서 1~7가지의 기능을 switch를 이용해서 각 기능을 접근할 수 있도록 해준다. 그리고 마지막에 0을 누르게 된다면 savedata함수로 인해 데이터파일에 저장되면서 코드가 끝나게 됩니다.


int readFile; // 데이터 읽고 메모리가 할당된 구조체 포인터 배열에 해당 정보를 집어넣어 줍니다.

void listData // 첫번째 기능으로써 화면에 내가 저장한 데이터를 출력해주는 함수입니다.
void findName // 지역명 찾기

int addData   // 목록 추가 
내가 입력한 정보인 지역, 한국인 세대수, 한국인수, 외국인수,를 *p(n)번째 해당하는 구조체 함수에 추가해주면 됩니다.
void editData // 목록 수정
// 지역이름(두글자 이상)적으면 그 글자(문자열)이 들어가 있는 구조체 내에 저장된 데이터들을 출력해주고 그 중 하나를 정해주는데 정할때! 구조체 배열의 번호를 이용해서 내가 수정할 데이터 내용 하나를 선택해준다. 그 이후 변공할 내용을 입력하고 데이터에 저장해준다.!
void statData // 통계 보기
인구, 외국인 비율, 세대당 인구수에 대한 각 max,min의 데이터들의 정보를 출력해주는 함수이다.
void ranking  // 순위 보기 총인구 수", "외국인 비율", "세대당 인구 수" 각 상하위 3개에 해당하는 저장된 데이터를 출력해주는 것입니다. 이때 각 상하위 3가지를 구현하는 방법은 무작위롤 되어있는 정보를 오름차순,  내림차순으로 정리해주는 방법을 사용할 것입니다.
만약에 2,5,4,3 배열을 2,3,4,5로 만들기 위해서는 2,5,4,3->2,4,5,3,->2,3,4,5가 됩니다. 그런 식으로 만들어 준 다음 여기서 3개의 정보만 쏙 빼내 주면 됩니다.

void saveFile // 데이터 저장
마지막에 0을 눌렀을 경우 내가 그 전까지 입력, 데이터 수정, 추가, 한 부분을 data.txt파일에 저장해주면서 끝나는 그런 함수입니다.

추가 기능인 void total// 총인구// 외국인 수// 세대수를 출력해주는 기능을 가진 함수입니다.여기서 총이란!! data.txt 파일에 저장된 모든 인구,외구인 수, 세대수를 말합니다.

void evalData(struct st_data *p);  // 구조체 데이터 내용 계산하는 함수입니다. 지역별 외국인 비율,지역별 한국인 세대당 인구수)
void printData(struct st_data *p); // 데이터 출력할때 구조체에 하나씩 저장된 데이터를 listdata에 불러서 출력해주는 기능을 가진 합니다.
int askMenu();                     // 메뉴 출력
"[ 1:List 2:Add 3:Edit 4:Find 5:Statistics 6:Ranking 7:total 0:Quit ]
 > Select a menu > "

struct st_data *getMaxData(struct st_data *p[], int size, int kind); // 특정 멤버가 가장 큰 값을 가진 데이터 찾기 

struct st_data *getMinData(struct st_data *p[], int size, int kind); // 특정 멤버가 가장 작은 값을 가진 데이터 찾기



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_data {
  char name[50];  // 지역명
  int family;     // 한국인 세대수
  int korean;     // 한국인 수
  int foreign;    // 외국인 수
  int total;      // 지역별 인구수 총합
  float fo_ratio; // 지역별 외국인 비율
  float fa_ratio; // 지역별 한국인 세대당 인구수
};

// data.txt 파일 구조
// 지역이름 한국인세대수 한국인수 외국인수

int readFile(struct st_data *p[], char filename[20]); // 데이터 읽기
void listData(struct st_data *p[], int size);         // 전체 목록 출력
void findName(struct st_data *p[], int size);         // 지역명 찾기
int addData(struct st_data *p[], int size);           // 목록 추가
void editData(struct st_data *p[], int size);         // 목록 수정
void statData(struct st_data *p[], int size);         // 통계 보기
void ranking(struct st_data *p[], int size);          // 순위 보기
void saveFile(struct st_data *p[], int size, char filename[20]); // 데이터 저장
void total(struct st_data *p[], int size);

void evalData(struct st_data *p);  // 구조체 데이터 내용 계산하기
void printData(struct st_data *p); // 데이터 출력
int askMenu();                     // 메뉴 출력
struct st_data *
getMaxData(struct st_data *p[], int size,
           int kind); // 특정 멤버가 가장 큰 값을 가진 데이터 찾기
struct st_data *
getMinData(struct st_data *p[], int size,
           int kind); // 특정 멤버가 가장 작은 값을 가진 데이터 찾기

int main(void) {
  struct st_data *data[20];
  int count;
  int menu, quit = 0, edited = 0;

  srand(time(0));
  count = readFile(data, "data.txt");
  printf("%d개 지역의 정보를 읽었습니다!\n", count);

  while (quit == 0) {
    menu = askMenu();
    switch (menu) {
    case 1:listData(data, count);
      break;
    case 2: count = addData(data, count); edited = 1;
      break;
    case 3:editData(data, count); edited = 1;
      break;
    case 4:findName(data, count);
      break;
    case 5:statData(data, count);
      break;
    case 6:ranking(data, count);
      break;
    case 7:total(data, count);
      break;
    case 0:  quit = 1;
      break;
    default: quit = 1;
    }
  }
  if (edited == 1) {
    int yesno;
    printf("데이터 파일을 저장할까요? (1 Yes 0 No) > ");
    scanf("%d", &yesno);

    if (yesno == 1)
      saveFile(data, count, "data.txt");
  }
  return 0;
}

int readFile(struct st_data *p[], char filename[20]) {
  int i = 0;
  FILE *file;
  file = fopen(filename, "r");
  while (!feof(file)) {
    char name[50];
    int n1, n2, n3;
    int size = fscanf(file, "%s %d %d %d", name, &n1, &n2, &n3);
    if (size < 4)
      break;
    
    p[i] = (struct st_data *)malloc(sizeof(struct st_data));
    strcpy(p[i]->name, name);
    p[i]->family = n1;
    p[i]->korean = n2;
    p[i]->foreign = n3;
    evalData(p[i]);
    i++;
  }
  fclose(file);
  return i;
}

void saveFile(struct st_data *p[], int size, char filename[20]) {
  // save fil!!
  FILE* fp;
  int i =0;
  fp = fopen(filename ,"w");
  for(i=0; i<size; i++){
    fprintf(fp,"%s %d %d %d\n",p[i]->name, p[i]->family,p[i]->korean,p[i]->foreign);
  }
  printf("%d개의 데이터를 저장했습니다.\n",i);
  fclose(fp);
}

void listData(struct st_data *p[], int size) {
  printf("전체 자료 (%d개 지역)\n", size);
  for (int i = 0; i < size; i++)
    printData(p[i]);
}

int addData(struct st_data *p[], int size) { // 입력한 데이터를 구조체 p에 저장하기
  struct st_data *n;
  char name[50];
  int n1, n2, n3;
  printf("새로운 자료 입력\n");
  printf(" > 지역 이름 : ");
  scanf("%s", name);
  printf(" > 한국인 세대수 : ");
  scanf("%d", &n1);
  printf(" > 한국인 수 : ");
  scanf("%d", &n2);
  printf(" > 외국인 수 : ");
  scanf("%d", &n3);
  //입력한 name n1,n2,n3를 구조체 포인터(동적할당한)n에 넣고 다시 p[size]에 넣는
  //작업을 해준다. TO DO:
  n = (struct st_data*)malloc(sizeof(struct st_data));
  strcpy(n->name,name);
  n->family = n1;
  n->korean = n2;
  n->foreign = n3;
  evalData(n);
  p[size] = n;
  //:TO DO
  return size + 1;
}

void editData(struct st_data *p[], int size) { //수정하기
  //생각 정리: 지역이름을 입력하면(두글자 이상)
  struct st_data *n;
  char name[50];
  char *pname; // strstr을 이용할 때 필요한 함수입니다.
  int count = 0, no;
  int n1, n2, n3;
  printf("자료 수정\n");
  // to do:
  while(1){
    printf("지역 이름은? >>");
    scanf("%s",name);
    if(strlen(name) > 1){
      break;
    }
  }
  for(int i =0; i<size; i++){
    pname = strstr(p[i]->name, name);
    if(pname == NULL){
      continue;
    }else{
      count =1;
      n = p[i];
      evalData(n);
      printf("[%d]",i);
      printData(n);
    }
  }
  if(count == 1){
    printf("위 지역 중에서 수정할 목록의 번호를 입력하시오.");
    scanf("%d",&no);
    for(int i =0; i< size; i++){
      if (no == i){
        evalData(n);
        printf("[%d]",i);
        printData(n);
      }
    }
    printf("변경할 내용을 입력하시오 >> \n");
    printf("한국인 세대 수 >> ");
    scanf("%d",&n1);
    printf("한국인 수 >> ");
    scanf("%d",&n2);
    printf("외국인 수 >> ");
    scanf("%d",&n3);
    p[no]->family = n1;
    p[no]->korean = n2;
    p[no]->foreign = n3;
    evalData(p[no]);  
    printf("수정 되었습니다.\n");
  }else{
    printf("잘못 입력했습니다.\n");
  }
 
}

void findName(struct st_data *p[], int size) {
  char name[50];
  int count = 0;
  printf("Enter a name > ");
  scanf("%s", name);
  for (int i = 0; i < size; i++) {
    if (strstr(p[i]->name, name)) {
      count++;
      printData(p[i]);
    }
  }
  printf("%d개의 자료를 찾았습니다.\n", count);
}

void statData(struct st_data *p[], int size) {
  //생각 정리
  struct st_data *s;
  printf("1) 가장 많은 인구가 사는 지역\n");
  s = getMaxData(p, size, 4);
  printData(s);

  printf("2) 가장 적은 인구가 사는 지역\n");
  s = getMinData(p, size, 4);
  printData(s);

  printf("3) 외국인 비율이 가장 높은 지역\n");
  s = getMaxData(p, size, 5);
  printData(s);

  printf("4) 외국인 비율이 가장 낮은 지역\n");
  s = getMinData(p, size, 5);
  printData(s);

  printf("5) 세대당 가장 많은 사람이 사는 지역\n");
  s = getMaxData(p, size, 6);
  printData(s);

  printf("6) 세대당 가장 적은 인구가 사는 지역\n");
  s = getMinData(p, size, 6);
  printData(s);
}

void ranking(struct st_data* p[], int size){ // 생각을 조금 해야될듯
  //일단은 evalData를 구해주고 p[i]에 전부 저장되게 한후에 상하위 3개 구하기
  //만약 원하는 랭킹 항목이 1,2,3인 경우 kind =1~3
   struct st_data* rank[3];
   int kind, order;
  struct st_data * temp;
   char kinds[3][50] = {"총인구 수", "외국인 비율", "세대당 인구 수"};
   char orders[2][50] = {"상위 3개", "하위 3개"};
   printf("원하는 랭킹 항목은? (1: 총인구 수, 2: 외국인 비율, 3: 세대당 인구 수) > ");
   scanf("%d", &kind);
   printf("원하는 랭킹 정렬은? (1: 상위 3개, 2: 하위 3개) > ");
   scanf("%d", &order);
  //evalData(p); // 데이터 저장하기 
  if(kind == 1){ // total rank
    if(order == 1){
     for(int i=0; i<size; i++)
      {
        for(int j=0;j<i; j++){ // 큰 순으로 정리하기
          if(p[i]->total > p[j]->total){
            temp = p[j];
            p[j] = p[i];
            p[i] = temp;
          }
        }
      }
      for(int i=0; i<3; i++){ // 3번째 자리까지 rank에 넣어주기
        rank[i] = p[i];
        evalData(rank[i]);
        printf("%d)",i);
        printData(rank[i]);
      }
    }else{
      for(int i=0; i<size; i++)// 작은 순으로 정리하기
      {
        for(int j=0;j<i; j++){
          if(p[i]->total < p[j]->total){
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
          }
        }
      }
     for(int i=0; i<3; i++){ // 3번째 자리까지 rank에 넣어주기
        rank[i] = p[i];
        evalData(rank[i]);
        printf("%d)",i);
        printData(rank[i]);
      }
    }
  }
  else if(kind == 2){ // fo_ratio rank
    if(order == 1){
     for(int i=0; i<size; i++)
      {
        for(int j=0;j<i; j++){ // 큰 순으로 정리하기
          if(p[i]->fo_ratio > p[j]->fo_ratio){
            temp = p[j];
            p[j] = p[i];
            p[i] = temp;
          }
        }
      }
      for(int i=0; i<3; i++){ // 3번째 자리까지 rank에 넣어주기
        rank[i] = p[i];
        evalData(rank[i]);
        printf("%d)",i);
        printData(rank[i]);
      }
    }else{ 
      for(int i=0; i<size; i++)// 작은 순으로 정리하기
      {
        for(int j=0;j<i; j++){
          if(p[i]->fo_ratio < p[j]->fo_ratio){
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
          }
        }
      }
     for(int i=0; i<3; i++){ // 3번째 자리까지 rank에 넣어주기
        rank[i] = p[i];
        evalData(rank[i]);
        printf("%d)",i);
        printData(rank[i]);
      }
    }
    
  }
  else{  // fa_ratio rank
    if(order == 1){
     for(int i=0; i<size; i++)
      {
        for(int j=0;j<i; j++){ // 큰 순으로 정리하기
          if(p[i]->fa_ratio > p[j]->fa_ratio){
            temp = p[j];
            p[j] = p[i];
            p[i]= temp;
          }
        }
      }
      for(int i=0; i<3; i++){ // 3번째 자리까지 rank에 넣어주기
        rank[i] = p[i];
        evalData(rank[i]);
        printf("%d)",i);
        printData(rank[i]);
      }
    }else{
      for(int i=0; i<size; i++)// 작은 순으로 정리하기
      {
        for(int j=0;j<i; j++){
          if(p[i]->fa_ratio < p[j]->fa_ratio){
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
          }
        }
      }
     for(int i=0; i<3; i++){ // 3번째 자리까지 rank에 넣어주기
        rank[i] = p[i];
        evalData(rank[i]);
        printf("[%d]",i);
        printData(rank[i]);
      }
    }
  }
}


int askMenu() { // 이미 구현된 것(교수님작품)
  int menu;
  printf("\n[ 1:List 2:Add 3:Edit 4:Find 5:Statistics 6:Ranking 7:total 0:Quit]\n");
  while (1) {
    printf(" > Select a menu > ");
    scanf("%d", &menu);
    if (menu >= 0 && menu <= 7)
      break;
    else
      printf(" > Wrong menu number!\n");
  }
  return menu;
}

void evalData(struct st_data *p) { // evalData도 완성됨
  p->total = p->korean + p->foreign;
  p->fa_ratio = 1.0 * p->korean / p->family;
  p->fo_ratio = 1.0 * p->foreign / p->total;
}

void printData(struct st_data *p) { // 이것도 완성됨
  printf("%s\n", p->name);
  printf(" > 인구 : %d명 (한국인 %d명, 외국인 %d명)\n", p->total, p->korean,
         p->foreign);
  printf(" > 외국인 비율 : 1천명 당 %.1f명\n", 1000 * p->fo_ratio);
  printf(" > 한국인 세대당 평균 가족 수 : %.3f명 (세대수 %d)\n", p->fa_ratio,
         p->family);
}

struct st_data *getMaxData(struct st_data *p[], int size, int kind) {
  // kind 가 4,5,6으로 경우에 따라 max를 구하고 그 결과 값(맥스값이 저장된
  // 구조체)을 statdata함수로 전달해준다.
  struct st_data *n;
  n = (struct st_data *)malloc(sizeof(struct st_data));
  
  if(kind == 4){
    n->total=0;
    for(int i=0; i<size; i++){
      if(p[i]->total > n->total){
        n = p[i];
        evalData(n);
      }
    }
  }
  else if(kind == 5){
    n->fo_ratio =0;
    for(int i=0; i<size; i++){
      if(p[i]->fo_ratio > n->fo_ratio){
        n = p[i];
        evalData(n);
      }
    }
  }
  else{
    n->fa_ratio =0;
    for(int i=0; i<size; i++){
      if(p[i]->fa_ratio > n->fa_ratio){
        n = p[i];
        evalData(n);
      }
    }
  }
  
  return n;
}

struct st_data *getMinData(struct st_data *p[], int size, int kind) {
  // kind 가 4,5,6으로 경우에 따라 min를 구하고 그 결과 값(min값이 저장된
  // 구조체)을 statdata함수로 전달해준다.
  struct st_data *n;
  n = (struct st_data *)malloc(sizeof(struct st_data));
  if(kind == 4){
      n->total = 10000000;
    for(int i=0; i<size; i++){
      if(p[i]->total < n->total){
        n = p[i];
        evalData(n);
      }
    }
  }
  else if(kind == 5){
      n->fo_ratio = 10000000;
    for(int i=0; i<size; i++){
      if(p[i]->fo_ratio < n->fo_ratio){
        n = p[i];
        evalData(n);
      }
    }
  }
  else{
      n->fa_ratio = 10000000;
    for(int i=0; i<size; i++){
      if(p[i]->fa_ratio < n->fa_ratio){
        n = p[i];
        evalData(n);
      }
    }
  }
  return n;
}
//추가 기능 넣기
void total(struct st_data *p[], int size){
  int k_total = 0;
  int fo_total = 0;
  int sedesu = 0;
  for(int i=0; i<size; i++){
    k_total = k_total + p[i]->korean;
  }
  for(int i=0; i<size; i++){
    fo_total = fo_total + p[i]->foreign;
  }
  for(int i=0; i<size; i++){
    sedesu = sedesu + p[i]->family;
  }
  printf("데이터에 저장된 지역의 총합은(한국인수, 외국인수, 세대수) >>\n");
  printf("한국인 수: %d\n",k_total);
  printf("외국인 수: %d\n",fo_total);
  printf("세대 수: %d\n",sedesu);
  return;
}

