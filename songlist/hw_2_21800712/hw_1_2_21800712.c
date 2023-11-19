//21800712 진세진 과제 1-2


#include <stdio.h>
int main(void) {
  // 이름 생년월일 넣고 자신의 생일은 월/일 년도로 바꿔서 출력하기
  // 변수사용 == 년도, 월,일, 이름
  int year, month, day ,DOB; 
  char name;
  
  printf("input your name: ");
  scanf("%s", &name);
  printf("input DOB as YYYYMMDD: ");
  scanf("%d", &DOB);

  // 년 월 일 게산하기 /(나누기), %(나눠서 몫을 출력)을 이용하여 계산한다.
  year = DOB / 10000;
  month = DOB / 100 % 100;
  day = DOB % 100;

  printf("Your birthday is %d /%d %d", month, day, year);
    
  
  return 0;
}