#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ArraySize 10

// srand(), rand(), time()


float GetMean(int array[], int size);
float GetVar(int array[], int size);
void GetMinMax(int array[], int size, int *min, int *max);

int main()
{
    srand(time(NULL));  // initialize random seed by current time
    int a[ArraySize] = { 0 };

    int i = 0;
    for(i = 0; i < ArraySize; i++)
        a[i] = rand();                  // range of rand() is [0, RAND_MAX]

    for(i = 0; i < ArraySize; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }

    float mean = GetMean(a, ArraySize);
    printf("mean = %f\n", mean);
//    printf("mean = %f\n", GetMean(a, ArraySize));

    float var = GetVar(a, ArraySize);
    
    int min = 0, max = 0;
    GetMinMax(a, ArraySize, &min, &max);

    return 0;
}

float GetMean(int array[], int size)
{
    float mean = 0.F;
    //int sum =0;
    for(int i =0; i<size;i++){
        mean +=array[i];   
    }
    // TO DO:
    mean /=size;
    return mean;
}

float GetVar(int array[], int size)
{
    float var = 0.F;
    int mean =0;
    int mean2=0;
    for(int i=0; i<size;i++){
        mean += (array[i] * array[i]);
        mean2 += array[i];
    }
    mean /=size;  // E[x^2]
    mean2 /=size;   // E[x]
    var = mean - (mean2 * mean2);
    // TO DO;

    return var;
}

void GetMinMax(int array[], int size, int *min, int *max)
{
    *max =0;
    for(int i =0; i<size; i++){
        if(array[i]>*max){
           *max = array[i];
        }
    }
    *min = *max;
    for(int i =0; i<size; i++){
        if(array[i]<*min){
           *min = array[i];
        }
    }

}