#include <stdio.h>

int main()
{
   int num = 5;
   int* ptr = NULL;
   int** ptr2 = NULL;

   ptr = &num; // ptr->num
   ptr2 = &ptr; // ptr2 -> ptr

   printf("num 주소: %p\n", &num);     //num 주소 출력
   printf("ptr 주소: %p\n", &ptr);     //ptr 주소 출력
   printf("ptr2 주소: %p\n\n", &ptr2); //ptr2 주소 출력

   printf("ptr이 가리키는 주소: %p(num의 주소)\n", ptr);     //ptr이 가리키는 주소 출력
   printf("ptr2이 가리키는 주소: %p(ptr의 주소)\n\n", ptr2); //ptr2이 가리키는 주소 출력

   printf("num 값: %d\n", num);            //num 값 출력
   printf("ptr 참조값: %d\n", *ptr);         //ptr 참조 값 출력
   printf("ptr2 참조값: %p\n", *ptr2);       //ptr2 참조 값 출력
   printf("ptr2 이중 참조값: %d\n", **ptr2); //ptr2 이중 참조 값 출력
   
   return 0;
}