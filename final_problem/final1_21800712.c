/*
    This program reads a text from the user and rotates the text around the screen until the user types ESC.
    Whenever the user presses space, it changes the direction.
    Complete the program by implementing RepeatText() and RotateRight().

    Compilation
    - On Windows: gcc final1_21800712.c Console.c -D_WINDOWS -Wall
    - On Mac: gcc final1.c Console.c -D_MAC -Wall

*/

#include <stdio.h>
#include <string.h>

#include "Console.h"

#define ESC 27

void RepeatText(char *text, int target_len);
void TrimText(char *text, int target_len);
void DrawTextRect(char *text, int left, int top, int right, int bottom);
void RotateLeft(char *text);
void RotateRight(char *text);

int main()
{
    {
/*
    Test code for RepeatText() and RotateRight().
    The output should be as follows:

        str = [Hello, World!]
        after RepeatText(), str = [Hello, World! Hello, World! Hello, World! Hello, W]
        after RotateRight(), str = [WHello, World! Hello, World! Hello, World! Hello, ]
        after RotateRight(), str = [ WHello, World! Hello, World! Hello, World! Hello,]
        after RotateRight(), str = [, WHello, World! Hello, World! Hello, World! Hello]
        after RotateLeft(), str = [ WHello, World! Hello, World! Hello, World! Hello,]
        after RotateLeft(), str = [WHello, World! Hello, World! Hello, World! Hello, ]
        after RotateLeft(), str = [Hello, World! Hello, World! Hello, World! Hello, W]

*/
        char str[256] = "";
        strcpy(str, "Hello, World!");
        printf("str = [%s]\n", str);
        RepeatText(str, 50);
        printf("after RepeatText(), str = [%s]\n", str);
        for(int i = 0; i < 3; i++){
            RotateRight(str);
            printf("after RotateRight(), str = [%s]\n", str);
        }

        for(int i = 0; i < 3; i++){
            RotateLeft(str);
            printf("after RotateLeft(), str = [%s]\n", str);
        }

        printf("Press Enter to continue: ");
        getchar();
    }

    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;

    clrscr();

    printf("screen size = %d x %d\n", screen_width, screen_height);

    char text[512] = "";
    printf("Input text: ");
    fgets(text, 512, stdin);
    int len = strlen(text) - 1;
    text[len] = 0;

    int left = 1;
    int right = screen_width;
    int top = 1;
    int bottom = screen_height;

    clrscr();
//    EnableCursor(FALSE);      // this line hides the cursor from the screen.
                                // enable it only after submitting all solutions
    int rect_perimeter = (right - left + 1) * 2 + (bottom - top + 1) * 2 - 4;
    if(len < rect_perimeter)
        RepeatText(text, rect_perimeter);
    else if(len > rect_perimeter)
        TrimText(text, rect_perimeter);

    char guide[] = "Press space to change direction and ESC to quit!";
    gotoxy((screen_width - strlen(guide)) / 2, screen_height / 2);
    printf("%s", guide);

    int dir = 0;
    while(1){
        int key = 0;
        if(kbhit()){
            key = getch();
            if(key == ' ')          // change direction on space
                dir = 1 - dir;
            else if(key == ESC)     // finish animation on ESC
                break;
        }

        DrawTextRect(text, left, top, right, bottom);

        // Rotate according to the value of dir
        if(dir == 0)
            RotateRight(text);
        else
            RotateLeft(text);

        gotoxy(1, screen_height);
        fflush(stdout);
        MySleep(20);
    }

    gotoxy(1, screen_height);
    printf("Bye!\n");

//    EnableCursor(TRUE);       // enable this line only after submitting all solutions

    return 0;
}

void DrawTextRect(char *text, int left, int top, int right, int bottom)
{
    int x = 0, y = 0;
    int t = 0;

    // draw the top side
    for(x = left; text[t] != 0 && x <= right; x++){
        gotoxy(x, top);
        putchar(text[t++]);
    }

    // draw the right side
    for(y = top + 1; text[t] != 0 && y <= bottom; y++){
        gotoxy(right, y);
        putchar(text[t++]);
    }

    // draw the bottom side
    for(x = right - 1; text[t] != 0 && x >= left; x--){
        gotoxy(x, bottom);
        putchar(text[t++]);
    }

    // draw the left side
    for(y = bottom - 1; y > top; y--){
        gotoxy(left, y);
        putchar(text[t++]);
    }
}

void RepeatText(char *text, int target_len)
// extend the string by repeating the input string
// insert a space character after each iteration
// e.g., if text == "Hello, World!", RepeatText(text, 50) makes text "Hello, World! Hello, World! Hello, World! Hello, W".
{
    // TO DO: implement this function
    //     if the length of text is smaller than target_len,
    //        add a space character (' ') at the end of text
    //        extend text to length target_len (set text[i] to text[i % len] for len <= i < target_len,
    //           where 'len' is the orignal length of the input text + 1, +1 is for the space.)
    char* pname;
    int len = strlen(text);
    if(len < target_len){
        text = strcat(text," ");
        for(int i=len; i<target_len; i++){
            text = strcat(text,"Hello, World! ");
            if(target_len < strlen(text)-1){
                text[target_len] ='\0';
                break;
            }
        }
    } 

}

void TrimText(char *text, int target_len)
{
    int len = strlen(text);
    if(len > target_len)
        text[target_len] = 0;
}

void RotateLeft(char *text)
// rotate a string one step left
// e.g., "HELLO" --> "ELLOH"
{
    int len = strlen(text);
    char temp = text[0];
    for(int i = 0; i < len - 1; i++)
        text[i] = text[i + 1];

    text[len - 1] = temp;
}

void RotateRight(char *text)
// rotate a string one step right
// e.g., "HELLO" --> "OHELL"
{
    // TO DO: implement this function
    // hint) It's behavior is the opposite of RotateLeft() 
    int len = strlen(text);
    char temp = text[len - 1];
    for(int i = len-2; i > 0; i--)
        text[i + 1] = text[i];

    text[0] = temp;


}
