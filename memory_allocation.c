/*memory allocation:
   requesting for a block of memory (memory size in bytes should be specified)
   on success, computer provides the starting address of the memory block
    // very important concept of  pointer in c.
   we need to declare a pointer variable because ...(we have to keep the address )
   if you have the address, you can access through * or [] operators

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p = NULL;
    int n = 0;

    // read the # of data
    printf("Input # of data: ");
    scanf(" %d ", &n);


    // allocate a dynamic memory block (keep the addres in a pointer)
    p = malloc(n* sizeof(int));
    // use the memory through * or [] operators
    for(int i = 0; i < n; i++)
        scanf("%d ",&p[i]);
    //getchar();
    for(int i=0; i < n; i++)
        printf("%d",p[i]);
    // release the memory block
    free(p);

    return 0;
}