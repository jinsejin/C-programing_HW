/*
    Mission: Find the largest element in the array

*/

#include <stdio.h>

int main()
{
    int a[10] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    int size = 10;

    for(int i = 0; i < size; i++)
        printf("%d-th element: %d\n", i, a[i]);

    int max = 0;
    // write your code here.

    // initialize max by a[0]
    max = a[0];
    // repeat for i from 1 to size
    int max_idx = a[0];
    for(int i = 1; i < size; i++){
    //     if a[i] is greater than max, update max by a[i]
        if(a[i] > a[max_index])
            a[max_index] = a[i];
    }
    
    printf("The largest element is %d\n", a[max_idx],max_idx);

    return 0;
}