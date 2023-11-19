//Pointer parameters
#include <stdio.h>

void function1(int x, int y);
void function2(int *x, int *y);
void function3(int **x, int **y);
void function4(int **x, int **y);

int main()
{
    int a = 10, b = 20;
    int *pa = &a;   // int *pa;     pa = &a;
    int *pb = &b;   // int *pb;     pa = &b;

    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(short) = %d\n", sizeof(short));

    printf("sizeof(int*) = %d\n", sizeof(int*));    
    printf("sizeof(short*) = %d\n", sizeof(short*));

    printf("Before function call: \n");
    printf("\ta = %d (%p), b = %d (%p)\n", a, &a, b, &b);
    printf("\tpa = %p (%p), pb = %p (%p)\n", pa, &pa, pb, &pb);


// Enable only one of the following function calls.
    // function1(a, b);                // function call #1

    // function2(&a, &b);           // function call #2
    // function2(pa, pb);           // function call #3

    // function3(&pa, &pb);      // function call #4
    // function4(&pa, &pb);      // function call #5

    printf("After function call: \n");
    printf("\ta = %d (%p), b = %d (%p)\n", a, &a, b, &b);
    printf("\tpa = %p (%p), pb = %p (%p)\n", pa, &pa, pb, &pb);

    return 0;
}

void function1(int x, int y)
{
    printf("In %s,\n", __func__);
    printf("\tx = %d (%p), y = %d (%p)\n", x, &x, y, &y);

    int temp = x;
    x = y;
    y = x;
}

void function2(int *x, int *y)
{
    printf("In %s,\n", __func__);
    printf("\tx = %p (%p), y = %p (%p)\n", x, &x, y, &y);
    printf("\t*x = %d, *y = %d\n", *x, *y);

    int temp = *x;
    *x = *y;
    *y = *x;
}

void function3(int **x, int **y)
{
    printf("In %s,\n", __func__);
    printf("\tx = %p (%p), y = %p (%p)\n", x, &x, y, &y);
    printf("\t*x = %p, *y = %p\n", *x, *y);
    printf("\t**x = %d, **y = %d\n", **x, **y);

    int *temp = *x;
    *x = *y;
    *y = *x;
}

void function4(int **x, int **y)
{
    printf("In %s,\n", __func__);
    printf("\tx = %p (%p), y = %p (%p)\n", x, &x, y, &y);
    printf("\t*x = %p, *y = %p\n", *x, *y);
    printf("\t**x = %d, **y = %d\n", **x, **y);

    int temp = **x;
    **x = **y;
    **y = **x;
}