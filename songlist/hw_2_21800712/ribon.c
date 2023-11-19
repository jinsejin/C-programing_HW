#include <stdio.h>

int main (void){
    
    int star1=0,star2=0;
    int blanks=0;
    int size=0;
    int i,j;
    printf("size> >> ");
    scanf("%d",&size);
    size=size*2-1;
    star1=1;
    star2=1;
    blanks=size+1-2;
    
    for(i=0;i<size;i++){
            for(j=0;j<star1;j++){
                printf("*");
            }
            for(j=0;j<blanks;j++){
                printf(" ");
            }
            for(j=0;j<star2;j++){
                printf("*");
            }
        
        if((size-1)/2> i){
            star1++; star2++;
            blanks-=2; 
         }
        else{
            star1--; star2--;
            blanks+=2;
        }
        printf("\n");
    } 
    return 0;
}
//리본 찍기
/*
1, size를 받는다.
2, size의 2배-1만큼의 높이를 가진 리본을 출력한다.

리본의 특징! 
height은 내가 입력한 size*2-1이다. (세로줄)
별 빈칸 별로 구성되있다    (가로줄)
이 (별 빈칸 별)의 시작은 
1(star) : size*2-2(blank) : 1(star)
이후에 별은 점점 커지고 중간점 이후에 다시 작아진다.(+1,-1)
이후에 빈칸은 점점 작아지다가 중간점 이후에 다시 커진다. (+-2개씩)
1, 중간점 이전
별의 증가 star1++; star2++;
빈칸의 감소 blanks-=2;
2, 중간점 이후
별의 감소 star1--; star--;
빈칸의 증가 blanks+=2;
여기서 중간점은 언제냐~? --> 별==size*2일때!
*/