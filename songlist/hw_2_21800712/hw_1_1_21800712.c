//21800712 진세진 과제 1
//ㅡ 원화를 달러로 바꾸기!
//1, 1 usd = 1380.06 krw
// 만약 1000000 krw라면 usd=는 726.61usd이다!! 즉 1usd/1380krw
// 모든 변수는 float변수로 사용
// 필요한 변수는 krw , usd만사용 하자

#include <stdio.h>
int main(void) {

  float krw , usd;
  float krw_rate = 1380.06; //각각 한화 , 달러 ,환율
    
  printf("input amount in KRW:"); //원화가 얼마인지를 출력하는 Printf문  사용
  scanf("%f", &krw); //원화가 얼마인지를 내가 입력하는 scanf문 사용 
    
  usd = krw / krw_rate ; //원화를 달러로 바꾸는 식
    
  printf("%.0f KRW = %.2f USD \n",krw ,usd);
      
  
  return 0;
}