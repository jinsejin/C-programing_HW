#include <stdio.h>


int main(void) {
  char digit[256] = "";
  int i=0;
  int even=0;
  int odd=0;
  //read a "input number~~" and input numbers
  printf("Input a string composed of three or more digits :");
  scanf("%s",digit);
  
  while(digit[i] != 0){
    int digit_i = digit[i] - '0'; // converts digit character into int.     (e.g., '3' -> 3)
    printf("%d-th digit = %d\n", i, digit_i);
    i++;
  }
  //find length of array  =>size of num(num[input num]/size of int
  printf("digits : %s \nlength of \"%d\" \n", digit , i);
  for(i=0;i<digit[i];i++){
    if(digit[i]%2==0){
      even++;
    }
    else odd++;
  }
  printf("%d even digits, %d odd digits",even,odd);
  return 0;
} 
/*for(i=0;i<size;i++){ //of the 10 array, repeat the for statement only lenght of size
    if(num[i]%2==0){
      even++;
    }
    else odd++;
    
  }
  //display number of the odd and even 
  printf("%d even digits, %d odd digits",even,odd);
*/