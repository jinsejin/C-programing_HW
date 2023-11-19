/*
    Draw rectangles on a text buffer (2D character array).
    Display the contents of the text buffer from the four sides (top, left, right, and bottom).
    See hw5_3_demo.mp4.
    gcc hw5_3.c Console.c -D_WINDOWS -Wall

*/
// i didn't make the code... so, i write the code now. 

#include <stdio.h>

#include "Console.h"

#define MAX_WIDTH 256
#define MAX_HEIGHT 256
char buffer[MAX_HEIGHT][MAX_WIDTH] = { 0 };     // text buffer

void DisplayBufferFromTop(int width, int height, char buffer[][MAX_WIDTH]);
void DisplayBufferFromLeft(int width, int height, char buffer[][MAX_WIDTH]);
void DisplayBufferFromRight(int width, int height, char buffer[][MAX_WIDTH]);
void DisplayBufferFromBottom(int width, int height, char buffer[][MAX_WIDTH]);

void ClearBuffer(int width, int height, char buffer[][MAX_WIDTH], char c);
void DrawRectangleOnBuffer(int width, int height, char buffer[][MAX_WIDTH], int left, int top, int right, int bottom);

int main()
{
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;

    // draw shape on buffer
    ClearBuffer(screen_width, screen_height, buffer, ' ');      // fill the 2D array with ' '
    DrawRectangleOnBuffer(screen_width, screen_height, buffer, 10, 5, 60, 20);
    DrawRectangleOnBuffer(screen_width, screen_height, buffer, 30, 2, 90, 15);

    // draw initial screen
    clrscr();
    printf("screen size = %dx%d\n", screen_width, screen_height);

    printf("Press Enter to continue: ");
    getchar();
 
    // display buffer from top side
    clrscr();
    DisplayBufferFromTop(screen_width, screen_height, buffer);  

    printf("Press Enter to continue: ");
    getchar();

    // display buffer from left side
    clrscr();
    DisplayBufferFromLeft(screen_width, screen_height, buffer);

    printf("Press Enter to continue: ");
    getchar();

    // display buffer from right side
    clrscr();
    DisplayBufferFromRight(screen_width, screen_height, buffer);

    printf("Press Enter to continue: ");
    getchar();

    // display buffer from bottom side
    clrscr();
    DisplayBufferFromBottom(screen_width, screen_height, buffer);

    gotoxy(1, screen_height);
    printf("Bye!\n");

    return 0;
}

void DisplayBufferFromTop(int width, int height, char buffer[][MAX_WIDTH])
{ 
    for(int y = 1; y <= height; y++){
        for(int x = 1; x <= width; x++){
            gotoxy(x, y);
            putchar(buffer[y - 1][x - 1]);
        }

        MySleep(50);            // wait for 50 msec
    }
    // TO DO: display buffer from the top side of the screen
    //      wait for 50 msec after drawing each row (see DisplayBufferFromBottom())
}

void DisplayBufferFromBottom(int width, int height, char buffer[][MAX_WIDTH])
{
    for(int y = height; y >= 1; y--){
        for(int x = 1; x <= width; x++){
            gotoxy(x, y);
            putchar(buffer[y - 1][x - 1]);
        }

        MySleep(50);            // wait for 50 msec
    }
    // display buffer from the bottom side of the screen
    //      wait for 50 msec after drawing each row (see DisplayBufferFromBottom())

}

void DisplayBufferFromLeft(int width, int height, char buffer[][MAX_WIDTH])
{
    for(int x = 1; x <= width; x++){
        for(int y = 1; y <= height; y++){
            gotoxy(x, y);
            putchar(buffer[y - 1][x - 1]);
        }

        MySleep(25);            // wait for 25 msec
    }
    // TO DO: display buffer from the left side of the screen
    //      wait for 25 msec after drawing each column
}

void DisplayBufferFromRight(int width, int height, char buffer[][MAX_WIDTH])
{
   for(int x = width; x >= 1; x--){
        for(int y = 1; y <= height; y++){
            gotoxy(x, y);
            putchar(buffer[y - 1][x - 1]);
        }

        MySleep(25);            // wait for 25 msec
    }
    // TO DO: display buffer from the right side of the screen
    //      wait for 25 msec after drawing each column
}

void ClearBuffer(int width, int height, char buffer[][MAX_WIDTH], char c)
// This function fills a text buffer with character c.
// Read this function carefully and learn how to pass a 2D array by a parameter.
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++)
            buffer[i][j] = c;
    }
}

void DrawRectangleOnBuffer(int width, int height, char buffer[][MAX_WIDTH], int left, int top, int right, int bottom)
// TO DO: Draw a rectangle on a 2D character array using character '*'
{
    // example) draw the top side
    for(int i = left; i <= right; i++)
        buffer[top - 1][i - 1] = '*';       // -1 is to convert range from [1 ... height][1 ... width] to [0 ... height-1][0 ... width-1]

    // TO DO: draw the left side
    for(int i = top; i <= bottom; i++)
        buffer[i - 1][left - 1] = '*';


    // TO DO: draw the right side
    for(int i = top; i <= bottom; i++)
        buffer[i - 1][right - 1] = '*';


    // TO DO: draw the bottom side
    for(int i = left; i <= right; i++)
        buffer[bottom - 1][i - 1] = '*';
}
