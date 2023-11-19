/*
    Write a program that reads a text line and displays all words in the input text.
    Complete the program by writing FindNextWord() and fixing Substring().
    DO NOT modify main().

    Example) The user types "God loves you    and  has  a wonderful plan      for your life.     "
        // Note the double space characters between words.

    Input text: God loves you    and  has  a wonderful plan      for your life.     
    start_idx = 0, end_idx = 3, substring = "God"
    start_idx = 4, end_idx = 9, substring = "loves"
    start_idx = 10, end_idx = 13, substring = "you"
    start_idx = 17, end_idx = 20, substring = "and"
    start_idx = 22, end_idx = 25, substring = "has"
    start_idx = 27, end_idx = 28, substring = "a"
    start_idx = 29, end_idx = 38, substring = "wonderful"
    start_idx = 39, end_idx = 43, substring = "plan"
    start_idx = 49, end_idx = 52, substring = "for"
    start_idx = 53, end_idx = 57, substring = "your"
    start_idx = 58, end_idx = 63, substring = "life."

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define MAX_WORD_LEN 64

int FindNextWord(char *str, int *start, int *end);
void Substring(char *str, int start, int end, char *substring);

int main()
{
//#define  DEBUG            // enable this line for debugging, if necessary. DON'T FORGET to disable this line before submission.
#ifdef  DEBUG
    char text[] = "God loves you    and  has  a wonderful plan      for your life.     ";
    printf("Input text: %s\n", text);
#else //  DEBUG
    char text[256] = "";
    printf("Input text: ");
    fgets(text, 256, stdin);
    text[strlen(text) - 1] = 0;
#endif //  DEBUG

    int start_idx = 0, end_idx = 0;

    while(FindNextWord(text, &start_idx, &end_idx)){
        printf("start_idx = %d, end_idx = %d, ", start_idx, end_idx);
        fflush(stdout);

        char substring[MAX_WORD_LEN] = "";
        Substring(text, start_idx, end_idx, substring);
        printf("substring = \"%s\"\n", substring);
    }

    return 0;
}

int FindNextWord(char *str, int *start, int *end)
// Finds the start and end indices of a word from the (*end)-th index.
// A word is a sequence of characters separated by whitespace characters.
//
// Input parameters:
//      - str: the input string
//      - start and end: pointers to the start and end indices found in the previous call. (initially, *start and *end are zero.)
// Output parameters:
//      - *start: the start index of the next string
//      - *end: the end index of the next string
// Return value: TRUE (1) if a word was found
//               FALSE (0) otherwise. (e.g., no more word after *end)
//
// e.g., If start_idx == 0 and end_idx == 6,
//       function call 'FindNextWord("Hello,  World! ", &start_idx, &end_idx);' results in start_idx == 8, end_idx == 14.
//
{
    printf("str = [%s], *start = %d, *end = %d\n", str, *start, *end);        // if necessary, enable this line for debugging. (disable before submission)

    // TO DO: Find the start index of a word.
    //        Initialize *start to *end, and increase it until *start reaches the end of string ('\0') or a non-whitespace character.
    //        Use isspace() to check whether a character is whitespace or not.
    // Hint) To increase *start, you need to use parentheses, as (*start)++.
    for(int i=*start; *str !='\0' || isspace(*str) != 0; i++){
        (*start)++;
    }
    // TO DO: If there is no remaining word, report failure.
    //        (If the (*start)-th character is the null character, set *start and *end to -1 for safety and return FALSE.)
    if(str[*start] =='\0'){
        return FALSE;
    }
    //TO DO: Find the end index of the word.
    //       Initialize *end to *start + 1, and increase it until *end //reaches the end of string ('\0') or a whitespace character.
    if( *str != '\0' || isspace(*str) != 0){
        *start = *end +1;
        *end += *start;
    }
    return TRUE;  
}

void Substring(char *str, int start, int end, char *substring)
// Build a substring composed of str[start] ~ str[end-1].
// e.g., after calling 'Substring("Hello, World!", 7, 12, substring);', substring should contain "World"
//
// TO DO: This function has a bug. Find and correct the bug. (Changing correct part will be penalize.)
//        Mark the modified parts by comments.
//        Assume the length of substring is greater than (end - start).
//        DO NOT use any standard function, such as strcpy(). gcc final2_21800712.c -Wall
{
    int i = 0, j = 0;

    for(i = start, j = 0; i < end; i++, j++){
        substring[j] = str[i];
        if(i == end -1){
            substring[j+1] = '\0'; 
        }
    }    
}
