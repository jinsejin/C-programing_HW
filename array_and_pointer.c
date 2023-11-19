#include <stdio.h>

int main()
{
    int a[10] = { 0 };

    for(int i = 0; i < 10; i++)
        a[i] = i;
    printf("a = %p\n", a);      
    printf("a[0] = %d, &a[0] = %p *(a+0) = %d\n", a[0], &a[0], *(a+0));
    printf("a[1] = %d, &a[1] = %p *(a+1) = %d\n", a[1], &a[1], *(a+1));
    printf("a[2] = %d, &a[2] = %p *(a+2) = %d\n", a[2], &a[2], *(a+2));

    return 0;
}
// point!! relation of array and pointer!!
// a == &a[0];
// &a[i] = a[0] + i *sizeof(int)
// &a[i] = a + i*sizeof(int)
// *(&a[i]) == a[i];
//*(a +i +sizeof(int)) = a[i];      // a : array (or address), i: interger and so on..elemente type!
// a[i] := *(a + i *sizeof(...)); >> the definition of a[i]!!
// &a[i] = a+i *sizeo(...) >> actually means >> <&a[i] = a + i>
// array name is a constant who's value is the starting address of the array