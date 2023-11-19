#include <stdio.h>

int main (){
    int a =0, b=0 , c =0;
    int* p =NULL, *q =NULL, *r =NULL;
    a=6;                         
    b =2; 
    p = &b;    //p = addresses of b(1004)
    
    q=p;  // q = addresses of p,b()
    r= &c;

    p = &a;
    *q= 8; // b= 8, why q의 주소는 b이기 때문에 b의 값이 변화가 된다.

    *r = *p; //*r == 6

    *r = *p + *q +*&c;  // 6+8+6 = 20

    return 0;
}