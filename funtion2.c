#include <stdio.h>
int ct_time();
int pt_time();
int rest_hourandmin();

int main(void) {
  int cur_hour,cur_min;// 현재시간,분 총현재시간
  int app_hour,app_min;
  int rest_time =0;
  
  printf("current time:");
  scanf("%02d %02d",&cur_hour,&cur_min);  
  printf("appointment time:");
  scanf("%02d  %02d",&app_hour,&app_min);  
 
  ct_time(cur_hour,cur_min); //전달 인자 있음 cur_hour,cur_min
  pt_time(app_hour,app_min); //전달 인자 있음 app_hour,app_min
  
  rest_time = pt_time(app_hour,app_min)-ct_time(cur_hour,cur_min);
  printf("rest time : %d min \n",rest_time);
  rest_hourandmin(rest_time);

  return 0;
}
int ct_time(int ch, int cm)
{ //남은 시간을 총분으로 계산하는 함수.
  int ctotal_t=0;
  
  ch *= 60; 
  ctotal_t=ch+cm;

  return ctotal_t;
}
int pt_time(int ah, int am)
{

  int atotal_t =0;
  
  ah *=60;
  atotal_t =ah+am;
  
  return atotal_t;
}
int rest_hourandmin(int rt)
{
  int hour, min;
  
  hour = rt / 60;
  min = rt % 60;
  printf("rest time= %02d :%02d \n",hour,min);
}