#include <stdio.h>
//3개 정수를 이용해서 최댓값 구하는 기본 알고리즘
//정수 a,b,c -> max 값 구하기! 
int maxnum(int a, int b, int c);
int main(){

    printf("max = %d",maxnum(3,2,1));
    printf("max = %d",maxnum(3,4,5));
    printf("max = %d",maxnum(3,3,3));
    printf("max = %d",maxnum(3,5,3));
    printf("max = %d",maxnum(4,2,3));
    printf("max = %d",maxnum(5,7,10));
    printf("max = %d",maxnum(1,2,2));
    printf("max = %d",maxnum(1,1,1));
    printf("max = %d",maxnum(5,20,45));

    return 0;
}
int maxnum(int a, int b, int c){
    int max =0;
    max = a;
    if(max < b) max = b;
    if(max < c) max = c;
    return max;
}