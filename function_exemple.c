
// display the time in total min.
# include <stdio.h>
 //declaration
int main(){
    int hour = 0;
    int min =0;
    int total_min =0;
    //read time in hour and min
    printf("hour and min? ");
    printf("%d %d",&hour,&min);
    total_in(hour, min, total_min);
//convert the time into total min (using a function)
// display the time in total min.

    return 0;
}
int total_in(int h,int m, int t){
    h=h*60;
    t = h+m;
    printf("total_min: %d", t);
}