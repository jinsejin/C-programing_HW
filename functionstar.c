#include <stdio.h>
#include <stdlib.h>
struct st_point{
  float x; // x좌표 값
  float y; // y좌표 값
};
struct st_point* getPoint(int j); // 메모리 할당받아 좌표 구조체의 x,y 값을 입력받아 이 주소값을 리턴함
int getPosition(struct st_point* p);
// 리턴값 : 좌표의 사분면 위치 (0:축, 1:1사분면, 2:2사분면, 3:3사분면, 4:4사분면)
// 수행내용 : 전달받은 좌표의 위치를 파악하여 위치번호(0~4)를 리턴함
int main(void){
  struct st_point* mypoint[10];
  int i=0;
  int point =0;
  int count[4] ={ 0 };
  int counts=0;
  for(i=0; i<10; i++){
    // 할당받은 메모리를 getPosition 함수에 넘겨 좌표위치 구하기
    mypoint[i] = getPoint(i);
    
  }
  for(int i=0; i<10; i++){
    point = getPosition(mypoint[i]);
    if(point == 0) counts++;
    else if(point == 1) count[0]++;
    else if(point == 2) count[1]++;
    else if(point == 3) count[2]++;
    else count[3]++;
    
    if(point == 0)
     printf("%d번째 좌표 축에 위치\n",i+1);
    else
      printf("%d번째 좌표 %d사분면에 위치\n",i+1, point);
  }
  printf("축의 좌표는 모두 %d개\n",counts);
  for(int i=0; i<4; i++)
    printf("%d사분면의 좌표는 모두 %d개\n",i+1,count[i]);
  
  return 0;
}
struct st_point* getPoint(int j){
  struct st_point* p = (struct st_point*)malloc(sizeof(struct st_point));
  printf("%d번째 좌표\n",j+1);
  printf("x, y값? ");
  scanf("%f %f",&p->x,&p->y);
  return p;
}
int getPosition(struct st_point* p){
  int reval = 0;
  if( p-> x > 0 && p-> y > 0) reval = 1;
  else if(p-> x < 0 && p-> y > 0) reval =2;
  else if(p-> x < 0 && p-> y < 0) reval =3;
  else if(p-> x > 0 && p-> y < 0) reval =4;
  else reval =0;
  return reval;
}