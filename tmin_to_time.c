#include <stdio.h>

void DivideTime(int tmin, int *hour, int *min);

int main()
{
    // read total min
    int total_min;
    int hour =0;
    int min =0;

    printf("input time in total min =");
    scanf("%d", &total_min);
    

    // divide total min into hour and min
    DivideTime(total_min,&hour,&min);
    // display time in 00:00
    printf("%02d:%02d",hour, min);

    return 0;
}

void DivideTime(int tmin,int *hour, int *min)
{   
    *hour = tmin / 60;
    *min = tmin % 60;
    //printf("%02d : %02d",*hour,*min);
}