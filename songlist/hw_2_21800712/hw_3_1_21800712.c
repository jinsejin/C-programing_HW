#include <stdio.h>
void GetStringLength(char *n){ //find string length 
    int len =0;

    while(*(n)++){

        len++;
    }
    printf("개수 :%d", len);
}
void DrawBar(char str[])
{  // Print the length and draw a horizontal bar with ‘#’ character.
	int num[10]; //the array valuable,for chaging string to array (num[10];)
	for (int i = 0; str[i] != '\0'; i++)
  {
		num[i] = str[i] - '0';  //change string to array

		printf("%d ", num[i]); //dispay num array i-th 
      for(int j=0; j<num[i];j++)
      {
        printf("#");  
      }
    printf("\n");
	}

}
//mian function
int main (){

    char number[15] ;
   
    printf("Input a digit string (up to 15 chars): ");
    scanf("%s", number);

    DrawBar(number); //calling function called Drawbar
    GetStringLength(number);//calling function called Getstringlength 

    
    
    
    return 0;
}
/*Write a C program that draws histogram
◼ Read a sequence of digits with a length of 15 or less as a string
◼ Display the length of the string
◼ Draw bars according to the digits
Example)
문자열을 사용해서 숫자를집어넣는다 
287289 인경우 >> 주소>> 2= 0칸, 8= 1칸~~ 나중에 길이 구할때 사용해야함

Input a digit string (up to 15 chars): 287289 //user input
len = 6 //using pointer don't use strlen() or similar standard function.
// using function called drawbar();
//첫번째 number[i]중 0일때 #을 두번 출력 그렇게 숫자 끝까지 반복해주자!후후

2: ##
8: ########
7: #######
2: ##
8: ########
9: #########

using function and pointer


*/