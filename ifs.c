#include <stdio.h>
int main()
{
int temperature = 0;
printf(“Input current temperature : ”);
scanf(“%d”, &temperature);
if(temperature >= 15 && temperature <= 25)
printf(“Good!\n”); // temperature is between 15 and 25
else
printf(“Bad!\n”); // otherwise
return 0;
}