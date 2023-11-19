//약속 시간과 현재시간을 나타낸 이후 현재시간 부터 약속시간까지의 남은 시간을 나타냄
// 1 현재시간과 약속시간을 출력하고 입력하는 printf, scanf 문을 사용하여
// 표출한다. 현재시간과 약속시간간의 사이의 시간을 계산
//변수 사용은
#include <stdio.h>

int main(void) {

      int app_hour, app_min, apppulsmin; //각각 약속 시간, 약속 분, 약속 시간의 총분
      int cur_hour, cur_min, curpulsmin; //각각 현재 시간, 현재 분, 현재 시간의 총분
      int rem_hour, rem_min, tmin; //각각 남은시간, 남은 분, 남은시간의 총분
    
      printf("input appointment time in HH MM: "); // 약속시간, 현재시간을 입력하기위한 printf, scanf 문 사용
      scanf("%02d  %02d", &app_hour, &app_min);
      printf("input current time in HH MM: ");
      scanf("%02d  %02d", &cur_hour, &cur_min);
    
      apppulsmin = app_hour * 60 + app_min; // total appointment time계산
      curpulsmin = cur_hour * 60 + cur_min; // total current time계산
      tmin = apppulsmin - curpulsmin;       // total remain time 계산
      rem_min = tmin % 60; // 남은 시간의 총분을 시간과 분으로 나눈다.
      rem_hour = tmin / 60;
    
      printf("remain time =%02d : %02d", rem_hour, rem_min); // 마지막으로 계산한 remain time을 출력

  return 0;
}