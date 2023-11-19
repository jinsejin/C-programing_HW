#include <stdio.h>

#include "console.h"
//Complete your solution by extending the following skeleton code.

int main(void)
{
    int screen_width = getWindowWidth(); // get the width of the screen
    int screen_height = getWindowHeight() - 3; // get the height of the screen (-3 is to avoid scroll)
    clrscr(); // clear screen
    int left = 0, top = 10, right = 0, bottom = 10;
    int i=0;

    printf("Screen size = %d x %d \n", screen_width, screen_height);
    
    printf("input number left top right bottom: ");        //TO DO: display the width and height of the screen
    scanf("%d %d ",&left, &top );     // TO DO: read left, top, right, and bottom from the user
    scanf("%d %d", &right, &bottom);
    
    
    for(i = left; i <= right; i++)
    { // TO DO: draw top boundary
        gotoxy(i, top);
        printf("*");
    }

    for(i = top; i <= bottom; i++)
    {// TO DO: draw left boundary
        gotoxy(left, i);
        printf("*");
    }
    for(i = left; i <= right; i++)
    { // TO DO: draw bottom boundary
        gotoxy(i, bottom);
        printf("*");
    }
                                      
    for(i = top; i <= bottom; i++)
    { // draw right boundary (example)
        gotoxy(right, i);
        printf("*");
    }
    
    gotoxy(1, screen_height);
    
    printf("Bye!\n");
    
    return 0;
}