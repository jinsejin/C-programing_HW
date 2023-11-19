#include<stdio.h>
#include <stdlib.h>

int main()
{
    int *p = NULL;
    int n = 0;

    // read the # of data
    printf("Input # of data: ");
    scanf("%d", &n);

    // allocate a dynamic memory block (keep the addres in a pointer)
    p = malloc(n * sizeof(int));

    // use the memory through * or [] operators
    // e.g. read n numbers 
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    // e.g., print the contents
    for(int i = 0; i < n; i++)
        printf("%d ", p[i]);    

    // release the memory block
    free(p);

    return 0;
}
/*



*/