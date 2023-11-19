#include <stdio.h>
int main(void){/// 시작이 가로 13 세로 10 
    int star1, star2;
    int blank1, blanks2;
    int size, row;
    int i,j;
   
   while(1){
    
    printf("size>>? ");
    scanf("%d",&size);
    printf("row>>?");
    scanf("%d",&row);
    star1 =3; star2 =3; blank1=2; blanks2 =5;

    if(size< 10 || row < 13){
        printf("다시 입력하시오\n");
    }
    else{
        break;
    }
   }

    for(i=0; i<size;i++){
        for(j=0;j<row;j++){
            for(int k=0;k<blank1;k++){
                printf(" ");
            }
            for(int k=0;k<star1;k++){
                printf("*");
            }
            for(int k=0;k<blanks2;k++){
                printf(" ");
            }
            for(int k=0;k<star2;k++){
                printf("*");
            }
            //세로3줄 이전과이후의 계산법
            if((size-1)/3 > i){
                blank1-= 2; blanks2-=2;
                star1 += 3; star2+=3;
            }
            else{
                for(int k=0;k<blank1;k++){
                    printf(" ");
                }
                for(int k=0;k<star1;k++){
                    printf("*");
                }
                for(int k=0;k<blanks2;k++){
                    printf(" ");
                }
                blank1++; blanks2++;
                star1 -= 2;
            }
        }
        printf("\n");
        
        //i=3번째 칸일경우 부터는 역 삼각형

   }


    return 0;
}



//하트 만들기
/* 가로 세로 변수 만들기
  
  ***     ***       blank1,2-=2; star1,2+=3 
 *****   *****
******* *******
 *************
  ***********
   *********     size-1/3 > i 
    *******
     *****
      ***
       *



처음 시작 값 ==> star1 =3 star2 =3 blank1=2 blanks2 =5  시작 가로 13 세로 10
int star1 star2;
int blank1 blanks2;
int size;

printf("size>>? ");
scanf("%d",&size);
*/