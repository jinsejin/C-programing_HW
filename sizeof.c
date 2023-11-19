#include <stdio.h>

int main()
{
    float num1 = 0;
    int size;

    size = sizeof(-345.23);    // 변수 num1의 자료형 크기를 구함

    printf("num1의 크기: %d\n", size);

    return 0;
}