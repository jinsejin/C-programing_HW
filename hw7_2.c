/*
    Write a program that displays shapes on the screen and allow the user to move ‘#’ symbol by keys:
        - ‘i’: up, ‘j’: left, ‘k’: down, ‘l’: right, ESC: quit
        - The ‘#’ symbol cannot path through the wall (‘*’ symbols).

        [hw7_2]
        - If there is an object at the coordinate to move and the next coordinate is empty, the '#' symbol can push it.        
        - However, the '#' symbol cannot push an object if the next coordinate is not empty. (It can push only one object.)
        
    Implement only the parts marked as "TO DO" and DO NOT modify other code.

    Read all the code carefully to learn coding techniques.

    Compilation command:
        Windows:    gcc hw7_2.c Console.c -D_WINDOWS -Wall
        Mac:        gcc hw7_2.c Console.c -D_MAC -Wall

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "Console.h"

#define ESC 27

#define MAX_OBJECT 10

// TO DO: define a structure to represent objects (tag: tMyObject)
// An object is represented by its type (an upper-case alphabet character) and integer coordinate (x, y)
// e.g., struct tMyObject ...
// TO DO: define a new type MyObject by aliasing 'struct tMyObject' using the typedef command.
typedef struct{
    char type;
    int x;
    int y;
}tMyObject;

tMyObject objects[MAX_OBJECT];       // array of objects
int no_object = 0;                  // # of objects


#define MAX_WIDTH 512
#define MAX_HEIGHT 512
char buffer[MAX_HEIGHT][MAX_WIDTH] = { 0 };     // text buffer

void AddObject(char type, int x, int y, char buffer[][MAX_WIDTH]);  // add a new object to the array 'objects'
void MarkObjectOnBuffer(int idx, char buffer[][MAX_WIDTH]);         // mark the idx-th object (objects[idx]) on the text buffer
void EraseObjectFromBuffer(int idx, char buffer[][MAX_WIDTH]);      // erase the idx-th object (objects[idx]) from the text buffer
void MoveObject(int idx, int dx, int dy, char buffer[][MAX_WIDTH]); // move the idx-th object (objects[idx]) to direction (dx, dy)


void ClearBuffer(int width, int height, char buffer[][MAX_WIDTH], char c);
// Reuse your solution to the previous homework for the following two functions
void DisplayBufferFromLeft(int width, int height, char buffer[][MAX_WIDTH]);
void DrawRectangleOnBuffer(int width, int height, char buffer[][MAX_WIDTH], int left, int top, int right, int bottom);

int main()
{
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;

    // draw shape on buffer
    ClearBuffer(screen_width, screen_height, buffer, ' ');      // fill the 2D array with ' '
    DrawRectangleOnBuffer(screen_width, screen_height, buffer, 10, 5, 70, 20);
    DrawRectangleOnBuffer(screen_width, screen_height, buffer, 30, 3, 90, 15);
    DrawRectangleOnBuffer(screen_width, screen_height, buffer, 1, 1, screen_width, screen_height);

    // make holes in the walls    
    buffer[14][77] = buffer[5][29] = buffer[3][89] = buffer[19][50] = buffer[2][54] = buffer[9][69] = ' ';

    clrscr();
    DisplayBufferFromLeft(screen_width, screen_height, buffer);

    AddObject('A', 40, 17, buffer);
    AddObject('B', 15, 10, buffer);

    gotoxy(1, screen_height);
    printf("Move '#' by pressing keys (i: up, k: down, j: left, l: right, ESC: quit). ");

    int x = screen_width / 2, y = screen_height / 2;
    buffer[y - 1][x - 1] = ' ';             // for safety

    // display '#' at the center of the screen
    gotoxy(x, y);
    putchar('#');

    // display the current coordinate
    gotoxy(2, 1);
    printf(" x = %d, y = %d ", x, y);

    gotoxy(screen_width, 1);                // move the cursor to the upper right corner

    int key = 0;
    while((key = getch()) != ESC){          // repeat reading keys until the user presses the ESC key
        int dx = 0, dy = 0;                 // direction to move
        // TO DO: update the direction (dx, dy) accoridng to key (use the switch statement)
        //      'i': move up (set dy to -1)
        //      'j': move left (set dx to -1)
        //      'k': move down (set dy to +1)
        //      'l': move right (set dx to +1)
        getch();
        key = getch();
        switch(key){
            case 'i': dy--;
                break;
            case 'j': dx--;
                break;
            case 'k': dy++;
                break;
            case 'l': dx++;
                break;
        } 
        // do not modify the following two lines.
        int newx = x + dx;      
        int newy = y + dy;
        //if there is an object at the new coordinate, push it.
        if(buffer[newy - 1][newx - 1] != ' ' && buffer[newy - 1][newx - 1] != '*'){
            int idx = buffer[newy - 1][newx - 1] - '0';
                MoveObject(idx, dx, dy, buffer);
        }
        // TO DO: if the new coordinate is empty, move (x, y) to (newx, newy),
        //      erase the current coordinate by printing a space character at (x, y)
        //      move to (newx, newy) by assiging (newx, newy) to (x, y).
        //      print '#' at (x, y)
        // Hint) Reuse your solution to the previous homework.
        if(buffer[newy -1][newx-1] == ' '){
            gotoxy(x, y);
            printf(" ");
            gotoxy(newx,newy);
            printf("#");
            dx=newx; dy=newy;
        }
        else{ 
            gotoxy(x,y);
            printf("#");
            gotoxy(newx,newy);
            printf("*");
        }
        // display current coordinate and move the cursor to the upper right corner
        gotoxy(2, 1);
        printf(" x = %3d, y = %3d ", x, y);
        gotoxy(screen_width, 1);
        fflush(stdout);
    }
    gotoxy(1, screen_height + 1);
    printf("Bye!\n");
    
    return 0;
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

void DisplayBufferFromLeft(int width, int height, char buffer[][MAX_WIDTH])
// TO DO: implement this function by reusing your solution to the previous homework
{
   for(int x = 1; x <= width; x++){
        for(int y = 1; y <= height; y++){
            gotoxy(x, y);
            putchar(buffer[y - 1][x - 1]);
        }

        MySleep(25);            // wait for 25 msec
    }
    // Display buffer from the left side of the screen
    //      wait for 25 msec after drawing each column

}

void DrawRectangleOnBuffer(int width, int height, char buffer[][MAX_WIDTH], int left, int top, int right, int bottom)
// Draw a MyRectangle on a 2D character array using character '*'
// TO DO: implement this function by reusing your solution to the previous homework
{
    // draw the top side
    for(int i = left; i <= right; i++)
        buffer[top - 1][i - 1] = '*';

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

void AddObject(char type, int x, int y, char buffer[][MAX_WIDTH])
// Add an object (type, x, y) to the array 'objects', mark it on the buffer, and display it on the screen
{
    //AddObject('A', 40, 17, buffer);
    // Add a new object into the array 'objects'
    objects[no_object].type = type;
    objects[no_object].x = x;
    objects[no_object].y = y;
    no_object++;
    // TO DO: Mark the new object on the buffer by calling MarkObjectOnBuffer()
    MarkObjectOnBuffer(type - '0',buffer);
    // TO DO: Display type at coordinate (x, y) on the screen (use gotoxy() and putchar())
    gotoxy(x ,y);
    putchar(type);
}

void MarkObjectOnBuffer(int idx, char buffer[][MAX_WIDTH])
{
    // store (idx + '0') into the coordinate of the object to quickly find the index of the object at the coordinate
    buffer[objects[idx].y - 1][objects[idx].x - 1] = idx + '0';
}

void EraseObjectFromBuffer(int idx, char buffer[][MAX_WIDTH])
{
    // store ' ' into the coordinate of the object
    buffer[objects[idx].y - 1][objects[idx].x - 1] = ' ';
}

void MoveObject(int idx, int dx, int dy, char buffer[][MAX_WIDTH])
// Move objects[idx] into direction (dx, dy) if the new coordinate is empty.
// After movement, the new coordinate should be (objects[idx].x + dx, objects[idx].y + dy)
{
    //TO DO: implement this function
    //      compute the new coordinate to move
    //      if the new coordinate is empty
    //          erase the object from the buffer by calling EraseObjectFromBuffer()       .
    //          erase the object by printing ' ' at the current coordinate of the object
    //          update the object coordinate to the new coordinate
    //          mark the object on the buffer by calling MarkObjectOnBuffer()
    //          display the object by printing its type at the new coordinate
    int newx = objects[idx].x + dx;
    int newy = objects[idx].y + dy;

    if(buffer[newy - 1][newx - 1] == ' ')
    {
        EraseObjectFromBuffer(idx,buffer); // erase the object by calling the function called EraseObjectFromBuffer();
        gotoxy(objects[idx].x ,objects[idx].y );
        putchar(' '); 
        gotoxy(dx,dy);          
        putchar('#');
        gotoxy(newx,newy);
        MarkObjectOnBuffer(idx,buffer);
    }
    // newx , newy ==> 
}
