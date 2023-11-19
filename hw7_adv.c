/*
    Write a program that displays shapes on the screen and allow the user to move ‘#’ symbol by keys:
        - ‘i’: up, ‘j’: left, ‘k’: down, ‘l’: right, ESC: quit
        - The ‘#’ symbol cannot path through the wall (‘*’ symbols).

        [hw7_2]
        - If there is an object at the coordinate to move and the next coordinate is empty, the '#' symbol can push it.        
        - However, the '#' symbol cannot push an object if the next coordinate is not empty. (It can push only one symbol.)

        [hw7_3]
        - Extend hw7_2 to read stage (rectangles, holes, and objects) from a text file.

        [hw7_adv]
        - Extand hw7_3 to let the user move objects to their target coordinates.
        
    Implement only the parts marked as "TO DO" and DO NOT modify other code.

    Read all the code carefully to learn coding techniques.

    Compilation command:
        Windows:    gcc hw7_adv.c Console.c -D_WINDOWS -Wall
        Mac:        gcc hw7_adv.c Console.c -D_MAC -Wall
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "Console.h"

#define TRUE 1
#define FALSE 0

#define ESC 27

#define CORRECT_TARGET 1
#define WRONG_TARGET -1

#define MISSION_COMPLETE_MESSAGE "Mission Completed! Congratulations!!!"
#define MISSION_FAILURE_MESSAGE "Mission Failure!"

#define MAX_OBJECT 10

#define STAGE_FILE "stage.txt"
#define MAX_RECT 128
#define MAX_HOLE 128


// [hw7_2]: define a structure to represent objects (tag: tMyObject)
// An object is represented by its type (an upper-case alphabet character) and integer coordinate (x, y)
// e.g., struct tMyObject ...
struct tMyObject {
    char type;                  // type of the object (a upper-case character)
    int x, y;                   // current coordinate
    int targetx, targety;       // target coordinate
};

// [hw7_2]: define a new type MyObject by aliasing 'struct tMyObject' using the typedef command.
typedef struct tMyObject MyObject;

MyObject objects[MAX_OBJECT];   // array of objects
int no_object = 0;              // # of objects


// TO DO: define a structure to represent rectangles using the 'typedef struct' syntax (type name: MyRectangle)
// a rectangle is represented the left, top, right, and bottom coordinates
typedef struct  {
    int left, top, right, bottom;
} MyRectangle;

MyRectangle rects[MAX_RECT];    // array of rectangles
int no_rect = 0;                // # of rectangles


// TO DO: define a structure to represnt a point using the 'typedef struct' syntax (type name: MyPoint)
// A point is represented by integer coordinates (x, y)
typedef struct {
    int x, y;
} MyPoint;

MyPoint holes[MAX_HOLE];        // array of holes
int no_hole = 0;                // # of holes


#define MAX_WIDTH 512
#define MAX_HEIGHT 512
char buffer[MAX_HEIGHT][MAX_WIDTH] = { 0 };     // text buffer

// object functions
void AddObject(char type, int x, int y, int targetx, int targety, char buffer[][MAX_WIDTH]);
void MarkObjectOnBuffer(int idx, char buffer[][MAX_WIDTH]);
void EraseObjectFromBuffer(int idx, char buffer[][MAX_WIDTH]);
int MoveObject(int idx, int dx, int dy, char buffer[][MAX_WIDTH]);
int IsEmpty(int x, int y, char buffer[][MAX_WIDTH]);
int IsObject(int x, int y, char buffer[][MAX_WIDTH]);
int IsTarget(int x, int y, char buffer[][MAX_WIDTH]);
int IsMissionCompleted();

// screen functions
void ReadScreen(char *file_name, char buffer[][MAX_WIDTH]);
void AddRectangle(int left, int top, int right, int bottom, char buffer[][MAX_WIDTH]);
void AddHole(int x, int y, char buffer[][MAX_WIDTH]);
void DisplayScreen();       // for debug

// screen buffer functions
void ClearBuffer(int width, int height, char buffer[][MAX_WIDTH], char c);
// Reuse your solution to the previous homework for the following two functions
void DisplayBufferFromLeft(int width, int height, char buffer[][MAX_WIDTH]);
void DrawRectangleOnBuffer2(int left, int top, int right, int bottom, char buffer[][MAX_WIDTH]);

int DisplayMessageUpperRight(char *message, int screen_width);
int DisplayMessageCenter(char *message, int screen_width, int screen_height);

int main()
{
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;

    char message[128] = "";

    // draw shape on buffer
    ClearBuffer(screen_width, screen_height, buffer, ' ');      // fill the 2D array with ' '

    // The following statements were replaced by ReadScreen() and AddRectasngle()
        // DrawRectangleOnBuffer(screen_width, screen_height, buffer, 10, 5, 70, 20);
        // DrawRectangleOnBuffer(screen_width, screen_height, buffer, 30, 3, 90, 15);
        // DrawRectangleOnBuffer(screen_width, screen_height, buffer, 1, 1, screen_width, screen_height);
        // make holes in the walls    
        // buffer[14][77] = buffer[5][29] = buffer[3][89] = buffer[19][50] = buffer[2][54] = buffer[9][69] = ' ';

    ReadScreen(STAGE_FILE, buffer);
    AddRectangle(1, 1, screen_width, screen_height, buffer);        // boundary

//#define  DEBUG                // for debugging, enable this directive
#ifdef  DEBUG
    clrscr();
    DisplayScreen();
    gotoxy(1, screen_height);
    printf("Press Enter: ");
    getchar();
#endif  //  DEBUG
   
    clrscr();
    DisplayBufferFromLeft(screen_width, screen_height, buffer);

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
        switch(key){
        case 'i':
            dy--;
            break;

        case 'j':
            dx--;
            break;

        case 'k':
            dy++;
            break;

        case 'l':
            dx++;
            break;
        }

        // do not modify the following two lines.
        int newx = x + dx;
        int newy = y + dy;

        // if there is an object at the new coordinate, push it.
        if(IsObject(newx, newy, buffer)){
            int idx = buffer[newy - 1][newx - 1] - 'A';      // retrieve the index of the object
            int ret = MoveObject(idx, dx, dy, buffer);

            sprintf(message, "MoveObject() returned %d", ret);
            DisplayMessageUpperRight(message, screen_width);

            if(ret == CORRECT_TARGET){
                sprintf(message, " Object #%02d is on the target coordinate.", idx);
                DisplayMessageUpperRight(message, screen_width);
                
                if(IsMissionCompleted()){
                    DisplayMessageCenter(MISSION_COMPLETE_MESSAGE, screen_width, screen_height);
                    break;
                }
            } else if(ret == WRONG_TARGET){                 // mission failure (the object stepped on a WRONG target.)
                sprintf(message, " Object #%02d is stepped on a WRONG TARGET!!!", idx);
                DisplayMessageUpperRight(message, screen_width);

                DisplayMessageCenter(MISSION_FAILURE_MESSAGE, screen_width, screen_height);
                break;
            }
        }

        // TO DO: if the new coordinate is empty, move (x, y) to (newx, newy),
        //      erase the current coordinate by printing a space character at (x, y)
        //      move to (newx, newy) by assiging (newx, newy) to (x, y).
        //      print '#' at (x, y)
        //
        // Hint) Reuse your solution to the previous homework.        
        if(IsEmpty(newx, newy, buffer)){
            // erase the current coordinate by printing a space character at (x, y)
            gotoxy(x, y);
            putchar(buffer[y - 1][x - 1]);

            // move to (newx, newy) by assiging (newx, newy) to (x, y).
            x = newx;
            y = newy;

            // print '#' at (x, y)
            gotoxy(x, y);
            putchar('#');
        } 

        // display current coordinate and move the cursor to the upper right corner
        gotoxy(2, 1);
        printf(" x = %3d, y = %3d ", x, y);
        gotoxy(screen_width, 1);
        fflush(stdout);
    }

    gotoxy(1, screen_height + 1);
    for(int i = 0; i < screen_width; i++)
        putchar(' ');
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
    // Display buffer from the left side of the screen
    //      call 'fflush(stdout);' after drawing each column to prevent problem on Mac
    //      wait for 25 msec after drawing each column
    for(int x = 1; x <= width; x++){
        for(int y = 1; y <= height; y++){
            gotoxy(x, y);
            putchar(buffer[y - 1][x - 1]);
        }

        fflush(stdout);
        MySleep(5);
    }
}

void DrawRectangleOnBuffer2(int left, int top, int right, int bottom, char buffer[][MAX_WIDTH])
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

void ReadScreen(char *file_name, char buffer[][MAX_WIDTH])
// read stage (rectangles, holes, and objects) from the text file.
{
    // TO DO: open the text file (on failure, display a proper message and quit.)
    FILE *fp = fopen(file_name, "r");
    if(fp == NULL){
        printf("Failed to open file %s in %s.\n", file_name, __func__);
        exit(-1);
    }

    // TO DO: repeat the following 
    //      read shape from the file as a string
    //      if fscanf() returns EOF, break the loop
    // 
    //      if the shape is "RECT"
    //          read left, top, right, and bottom from the file
    //          add the rectangle by calling AddRectangle()    //
    //      else if the shape is "HOLE"
    //          read x and y from the file
    //          add the hole by calling AddHole()
    //      else if the shape is "OBJECT"
    //          read type, x, and y form the file
    //          add the object by calling AddObject()
    while(1){
        char shape[16] = "";
        int ret = fscanf(fp, "%s", shape);
        if(ret == EOF)
            break;

        if(shape[0] == '#'){        // commment
            char buffer[128] = "";
            fgets(buffer, 128, fp);
            continue;
        }

        if(strcmp(shape, "RECT") == 0){
            int left = 0, top = 0, right = 0, bottom = 0;
            fscanf(fp, "%d %d %d %d", &left, &top, &right, &bottom);
            AddRectangle(left, top, right, bottom, buffer);
        } else if(strcmp(shape, "HOLE") == 0){
            int x = 0, y = 0;
            fscanf(fp, "%d %d", &x, &y);
            AddHole(x, y, buffer);
        } else if(strcmp(shape, "OBJECT") == 0){
            char type = 0;
            int x = 0, y = 0, targetx = 0, targety = 0;
            fscanf(fp, " %c %d %d %d %d", &type, &x, &y, &targetx, &targety);
            AddObject(type, x, y, targetx, targety, buffer);
        } else {
            printf("Invalid shape: %s\n", shape);
            break;
        }
    }

    // TO DO: close the text file
    fclose(fp);
}

void DisplayScreen()
// display shapes for debugging
{
    for(int i = 0; i < no_rect; i++)
        printf("rects[%d] = %d %d %d %d\n", i, rects[i].left, rects[i].top, rects[i].right, rects[i].bottom);

    for(int i = 0; i < no_hole; i++)
        printf("holes[%d] = %d %d\n", i, holes[i].x, holes[i].y);

     for(int i = 0; i < no_object; i++)
        printf("objects[%d] = %c %d %d %d %d\n", i, objects[i].type, objects[i].x, objects[i].y, objects[i].targetx, objects[i].targety);
}

void AddRectangle(int left, int top, int right, int bottom, char buffer[][MAX_WIDTH])
{
    // TO DO: add a rectangle (left, top, right, bottom) to the array 'rects'
    rects[no_rect].left = left;
    rects[no_rect].top = top;
    rects[no_rect].right = right;
    rects[no_rect].bottom = bottom;
    no_rect++;

    // draw the rectangle on the buffer
    DrawRectangleOnBuffer2(left, top, right, bottom, buffer);
}

void AddHole(int x, int y, char buffer[][MAX_WIDTH])
{
    // TO DO: add a point (x, y) to the array 'holes'
    holes[no_hole].x = x;
    holes[no_hole].y = y;
    no_hole++;

    // TO DO: mark the hole on the buffer 
    //      put ' ' at the coordinate of the point on the buffer
    buffer[y - 1][x - 1] = ' ';
}

void AddObject(char type, int x, int y, int targetx, int targety, char buffer[][MAX_WIDTH])
// Add an object (type, x, y) to the array 'objects', mark it on the buffer, and display it on the screen
{
    // Add a new object into the array 'objects'
    objects[no_object].type = type;
    objects[no_object].x = x;
    objects[no_object].y = y;
    objects[no_object].targetx = targetx;
    objects[no_object].targety = targety;

    // [hw7_2]: Mark the new object on the buffer by calling MarkObjectOnBuffer()
    MarkObjectOnBuffer(no_object, buffer);

    // [hw7_2]: Display type at coordinate (x, y) on the screen (use gotoxy() and putchar())
    // display object
    gotoxy(x, y);
    putchar(type);

    // display target
    gotoxy(targetx, targety);
    putchar(tolower(objects[no_object].type));

    no_object++;
}

void MarkObjectOnBuffer(int idx, char buffer[][MAX_WIDTH])
{
    buffer[objects[idx].y - 1][objects[idx].x - 1] = idx + 'A';
    buffer[objects[idx].targety - 1][objects[idx].targetx - 1] = idx + 'a';
}

void EraseObjectFromBuffer(int idx, char buffer[][MAX_WIDTH])
{
    buffer[objects[idx].y - 1][objects[idx].x - 1] = ' ';
}

int MoveObject(int idx, int dx, int dy, char buffer[][MAX_WIDTH])
// Move objects[idx] into direction (dx, dy) if the new coordinate is empty.
// After movement, the new coordinate should be (objects[idx].x + dx, objects[idx].y + dy)
{
    // [hw7_2]: implement this function
    //      compute the new coordinate to move
    //      if the new coordinate is empty
    //          erase the object from the buffer by calling EraseObjectFromBuffer()       .
    //          erase the object by printing ' ' at the current coordinate of the object
    //          update the object coordinate to the new coordinate
    //          mark the object on the buffer by calling MarkObjectOnBuffer()
    //          display the object by printing its type at the new coordinate

    int newx = objects[idx].x + dx;
    int newy = objects[idx].y + dy;

    if(IsEmpty(newx, newy, buffer)){
        EraseObjectFromBuffer(idx, buffer);
        gotoxy(objects[idx].x, objects[idx].y);
        putchar(' ');

        objects[idx].x = newx;
        objects[idx].y = newy;

        gotoxy(newx, newy);
        putchar(objects[idx].type);

        // check if object[idx] is on a target
        if(IsTarget(newx, newy, buffer)){
            if(buffer[newy - 1][newx - 1] - 'a' == idx){        // correct target
                buffer[newy - 1][newx - 1] = '@';       // mark '@' on the buffer to fix the object a the target coordinate
                return CORRECT_TARGET;
            } else {                                            // wrong target
                return WRONG_TARGET;
            }
        }

        MarkObjectOnBuffer(idx, buffer);
    }

    return FALSE;       // object[idx] is not on the target coordinate
}

int IsEmpty(int x, int y, char buffer[][MAX_WIDTH])
{
    char c = buffer[y - 1][x - 1];
    return (c == ' ' || islower(c)) ? TRUE : FALSE;
}

int IsObject(int x, int y, char buffer[][MAX_WIDTH])
{
    return isupper(buffer[y - 1][x - 1]) ? TRUE : FALSE;
}

int IsTarget(int x, int y, char buffer[][MAX_WIDTH])
{
    return islower(buffer[y - 1][x - 1]) ? TRUE : FALSE;
}

int IsMissionCompleted()
{
    int i = 0;
    for(i = 0; i < no_object; i++){
        if(objects[i].x != objects[i].targetx || objects[i].y != objects[i].targety)
            break;
    }

    return (i == no_object) ? TRUE : FALSE;
}

int DisplayMessageUpperRight(char *message, int screen_width)
{
    gotoxy(screen_width - strlen(message), 1);
    printf("%s", message);
}

int DisplayMessageCenter(char *message, int screen_width, int screen_height)
{
    int len = strlen(message);

    // clear background area
    int left = (screen_width - len + 1) / 2 - 1;
    int right = (screen_width + len + 1) / 2 + 2;
    int top = screen_height / 2 - 1;
    int bottom = screen_height / 2 + 2;    

    for(int y = top; y < bottom; y++){
        gotoxy(left, y);
        for(int x = left; x < right; x++)
            putchar(' ');
    }

    // display message at center
    gotoxy((screen_width - len) / 2, screen_height / 2);
    printf("%s", message);
}
