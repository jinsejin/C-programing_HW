/*
    This program reads a text from the user and repeats stretching and shrinking the text.
    See hw6_2.mp4.

    Complete the program by implementing the following functions:
        StretchString(): make a stretched string (e.g. calling with a text "HELLO" and a stride of 2 produces "H E L L O")
        ReverseString(): reverse a string (e.g.. "HELLO" --> "OLLEH")

    Read all code carefully to learn coding techniques.

    Implement only the above functions and DO NOT modify other code.    

    Compilation command:
        Windows:    gcc hw6_2_21800712.c Console.c -D_WINDOWS -Wall
        Mac:        gcc hw6_2.c Console.c -D_MAC -Wall

*/
//!!!!-->  i'am sorry ...i don't konw how to fix the code;;; 

#include <stdio.h>
#include <string.h>

#include "Console.h"

#define MAX_LEN 256
#define MAX_STRIDE 4

#define ESC 27   // ASCII code of the ESC character

// TO DO: declare StretchString() and ReverseString() with proper parameters and return types.

int* StretchString(char str[],int n,char strect[],int* p);
char* ReverseString(char str[],int l);
void Erase(int x, int y, int len);

int main()
{
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;

    char text[MAX_LEN] = { 0 };
    char stretched[MAX_LEN] = { 0 };
    

    clrscr();
    printf("Input text: ");
    fgets(text, MAX_LEN, stdin);
    int len = strlen(text) - 1;

    if(len > screen_width / 4)      // for safety
        len = screen_width / 4;
    text[len] = 0;                  // trim '\n'
    
    int cx = screen_width / 2;
    int cy = screen_height / 2;

    if(0){// to enable the following test code, replace 0 by 1
          // test code for StretchString() and ReverseString()

        int len2 = 0;
        for(int i = MAX_STRIDE; i >= 1; i--){
            StretchString(text, i, stretched, &len2);
            printf("%s\n", stretched);
        }

        ReverseString(text, len);

        for(int i = 1; i <= MAX_STRIDE; i++){
            StretchString(text, i, stretched, &len2);
            printf("%s\n", stretched);
        }

        return 0;
    }

    printf("Press ESC to finish.");

    int max_len = len * MAX_STRIDE;
    
    gotoxy(cx - len / 2, cy);
    printf("%s", text);

    while(!kbhit() || getch() != ESC){      // repeat until the user presses ESC
        int len2 = 0;

        for(int i = MAX_STRIDE; i >= 1; i--){
            Erase(cx - (max_len / 2) - 1, cy, max_len + 2);

            StretchString(text, i, stretched, &len2);

            gotoxy(cx - len2 / 2, cy);
            printf("%s", stretched);

            MySleep(250);
        }

        ReverseString(text, len);

        for(int i = 1; i <= MAX_STRIDE; i++){
            Erase(cx - (max_len / 2) - 1, cy, max_len + 2);

            StretchString(text, i, stretched, &len2);

            gotoxy(cx - len2 / 2, cy);
            printf("%s", stretched);

            MySleep(250);   
        }
    }
    gotoxy(1, screen_height);
    printf("Bye!\n");

    return 0;
}

// TO DO: Write the header of the function StretchString().
//      - input parameters: a text (char array) and a stride (int)
//      - ouput parameters: the stretched text (char array) and the length of the stretched text (int *)
//  * Assume the caller function provides a sufficiently long char array to receive the stretched text.
int* StretchString(char str[],int n,char strect[],int* p){
    // TO DO: implement the function body
    // Hint) Don't forget to put a null character (0) at the end of the stretched string.
   int count =strlen(str);
   char blank[5] ={ 0 };
   int i=0;
   *p=count+(n*(count-2));
   for(int i=0; i<n; i++){ //make blank string to repeat n counts for inputing blank.
        blank[i] = ' ';
        if(i==n-1){
            blank[i+1] ='\0';
        }
    }  
   for(i=0; i<count; i++)
   {
        if(i==count-1){ //if last str[count-1](strlen(str)-1) strect input str[i]; and 
            strect[*p] = str[i];
            //strcat(strect,blank); 
            //strect[*p+1] = '\0';
            break;
        }        
        else{
            strect[i+(n*i)] = str[i];
            strect[i+(n*i)+1] = '\0';
            strcat(strect,blank);
        }
   }
    return p; // output is strect point p (=  address of len2)  // strect sting + blank string;
}
// TO DO: write the header of the function ReverseString()
//      input/output parameter: a string (char array)
//      input parameter: the length of the string(int)
char* ReverseString(char str[],int l){ // ok!
    // TO DO: implement the function body
    char reverse[MAX_LEN] ={ 0 };
    int j=0;
    for(int i=l; i>=0;i--){ // 뒤에 있는 걸 앞으로 가져오는 작업을 문자열의 첫번째까지 해준다. 
        reverse[j] = str[i-1];
        if(i==0){
            str[l] = '\0';
            break;
        }
        j++;  
    }
    for(int i=0; i<l;i++){ // 뒤에 있는 걸 앞으로 가져오는 작업을 문자열의 첫번째까지 해준다. 
        str[i] = reverse[i];
        if(i==l-1){
            str[l] = '\0';
            break;
        }
    }
    return str;
}
void Erase(int x, int y, int len)
{
    gotoxy(x, y);
    for(int i = 0; i < len; i++)
        putchar(' ');
}
/*gcc hw6_2_skeleton.c console.c -D_WINDOWS -Wall*/