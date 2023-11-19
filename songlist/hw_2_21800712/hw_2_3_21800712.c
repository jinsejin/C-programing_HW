#include <stdio.h>

int main(void) {
  int min =0;
  int sec=0;
  int plus_sec=0;
  int i=0;
  printf("Input current time MM SS: ");
  scanf("%d %d", &min, &sec);
  
  printf("Input elapsed time in sec: ");
  scanf("%d",&plus_sec);
  
  printf("start time: %d : %d\n",min,sec);
  
  for(i=0; i<plus_sec;i++){
      sec++;
    if(sec==60){
      min++;
      sec=0;
    }
    if(min==60){
      min=0;
    }
     printf("after 1 sec: %02d : %02d\n",min,sec);
  }
  return 0;
}
/*
Read current time (start time) in min and sec.
◼ Read elapsed time in sec.
◼ Display start time
◼ Repeat for elapsed time
 Increase sec
 If sec is greater than or equal to 60,
 Reset sec to zero
 Increase min
 If min is greater than or equal to 60, reset min to zero
 Display tim
*/
//현재 분과 초를 입력하고 몇초가 지나면 그 시간의 경과를 출력하는 콛
// 1, 현재 분과 초를 입력한다
//증가는 초가 증가하고 만약 초가 60초가 지나면 분이 ++한다.
/*
대충 코드를 짜보자
for문이 좋을 듯(조건문 사용은)
printf
scanf 를 사용해서 현재 분초 입력 과 얼마나 시간이 경과하는 지 내가 입력한다.

*/