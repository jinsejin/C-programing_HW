#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shufflebingo(int b[]);
int markbingo(int num, int b[]);
void bingos(int b[]);
int main(void){
    int bingo[25]; //bingo칸 만들기
    int number; // 내가 넣은 number
   // int i=0;
    int cheak;
    int counts =0;
    // 처음으로 빙고판 만들기
    srand(time(0));
    for(int i=0; i<25; i++)
        bingo[i] = i+1;
    shufflebingo(bingo); // 빙고 섞기
    bingos(bingo); // 빙고 출력
    while(1){// 숫자 입력하기
        printf("input number: ");
        scanf(" %d ",&number);
        if(number<1 && number>25){ // 1~25가 넘어가면
            printf("EXIT");
		    break;
        }
        else{
            cheak = markbingo(number,bingo);
            if(cheak != 0)
                counts++;
            if(cheak == 1)
                break; 
        }
    }
    //내가 입력한 빙고판 (즉 빙고일 경우) 출력
     bingos(bingo);
     printf("try : %d",counts);
    
    return 0;
}
void shufflebingo(int b[]){
    int x,y, temp;
    for(int i=0; i<50; i++){ // x y를 25번 섞어 준다.
        x= rand() % 25;
        y= rand() % 25;
        temp = b[x];
        b[x] = b[y];
        b[y]= temp;
    }
}
int markbingo(int num, int b[]){
    // 빙고 =>1
    // 빙고 가 아닌데 0으로 변신한 것 -1
    // 중복일때 0으로 반환하기
    int reval =0; // 기본적으로 0 why? 중복을 위해서!
    int row, col;
    int count =0;
    for(int i =0; i<25; i++){
        row = i/5; col = i%5;
        if(b[i] == num){
            b[i] = 0;
            reval = -1;
        }
        for(int j=0; j<5; j++) // 가로 빙고
            if(b[row*5+j] == 0) count++;
        if(count ==5){
            reval = 1;
            //printf("%d번째 가로 빙고\n",row+1);
            break;
        }
        count=0;
        for(int j=0; j<5; j++) // 세로 빙고
            if(b[col+(j*5)] == 0) count++;
        if(count ==5){
            reval = 1;
           // printf("%d번째 세로 빙고\n",col+1);
            break;
        }
        count=0;
        for(int j=0; j<5; j++) // 대각선 빙고
            if(b[j*6] == 0) count++;
        if(count ==5){
            reval = 1;
            //printf("대각선 빙고\n");
            break;
        }
        count=0;
        for(int j=0; j<5; j++) // 대각선 빙고
            if(b[(j+1)*4] == 0) count++;
        if(count ==5){
            reval = 1;
           // printf("대각선 빙고\n");
            break;
        }
        count =0;
        // 가로 빙고 세로 빙고 대각선 빙고 판별하기
        // 가로 빙고를 판별하기 위해서! 
    }
    if(reval == 0)
        printf("duplication! ");

    return reval;
}
void bingos(int b[]){
    int i;
    printf("BINGO MATRIX\n");
    for(i=0; i<25; i++){
        if(i % 5 == 0)
            printf("---------------------------\n|");
        printf(" %2d |",b[i]); 
        if(i % 5 == 4)
            printf("\n");      
    }
    printf("---------------------------\n");
}
/*
bingo 만들기
1~25
5*5 칸에 1~25 랜덤하게 집어넣기
일단 예시로 넣어 놨다.
1  2  3  4  5 
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
그리고 내가 입력한 수가 있는 칸을 0으로 바꿔준다.
*/