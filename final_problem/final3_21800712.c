/*
    Write a program that reads a text line, shuffles the words in the input text, and concatenate the suffled words into a text.
    Implement AddWord() and ShuffleWords().
    DO NOT modify main().

    Example) The user types "God loves you and has a wonderful plan for your life."
        Input text: God loves you and has a wonderful plan for your life.                                                     
        ### Before shuffle: 11 words
        word   0: 0 3 "God"
        word   1: 4 9 "loves"
        word   2: 10 13 "you"
        word   3: 14 17 "and"
        word   4: 18 21 "has"
        word   5: 22 23 "a"
        word   6: 24 33 "wonderful"
        word   7: 34 38 "plan"
        word   8: 39 42 "for"
        word   9: 43 47 "your"
        word  10: 48 53 "life."
        ### After shuffle: 11 words
        word   0: 10 13 "you"
        word   1: 48 53 "life."
        word   2: 39 42 "for"
        word   3: 34 38 "plan"
        word   4: 4 9 "loves"
        word   5: 0 3 "God"
        word   6: 24 33 "wonderful"
        word   7: 43 47 "your"
        word   8: 14 17 "and"
        word   9: 18 21 "has"
        word  10: 22 23 "a"
        shuffled text = "you life. for plan loves God wonderful your and has a"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define MAX_WORD 256
#define MAX_WORD_LEN 64

// TO DO: declare a structure type 'Word' to store words using the 'typedef struct' syntax.
//      A word is represented by the start and end indices (int) and a character array of size MAX_WORD_LEN.
typedef struct {
    int start, end;
    char word[MAX_WORD_LEN];
} Word;

Word words[MAX_WORD];       // an array of words
int no_word = 0;            // # of words

void DisplayWords(Word words[], int n);
void AddWord(char *str, int start, int end);
void ShuffleWords(Word words[], int n);
void ConcatAllWords(Word words[], int n, char text[]);

int FindNextWord(char *str, int *start, int *end);

int main()
{
    // TO DO: initialize random seed by current time
    srand(time(NULL));
//#define  DEBUG            // enable this line for debugging, if necessary. DON'T FORGET to disable this line before submission.
#ifdef  DEBUG
    char text[] = "God loves you and has a wonderful plan for your life.";
    printf("Input text: %s\n", text);
#else  //  DEBUG
    char text[256] = "";
    printf("Input text: ");
    fgets(text, 256, stdin);
    text[strlen(text) - 1] = 0;
#endif  //  DEBUG
        
    int start_idx = 0, end_idx = 0;
    
    while(FindNextWord(text, &start_idx, &end_idx))
        AddWord(text, start_idx, end_idx);

    printf("### Before shuffle: ");
    DisplayWords(words, no_word);

    ShuffleWords(words, no_word);
    printf("### After shuffle: ");
    DisplayWords(words, no_word);

    ConcatAllWords(words, no_word, text);
    printf("shuffled text = \"%s\"\n", text);

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
//      -*start: the start index of the next string
//      - *end: the end index of the next string
// Return val ue: TRUE(1) if a word was found
//               FALSE(0) otherwise. (e.g., no more word after *end)
//
// e.g., If start_idx == 0 and end_idx == 6,
//       function call 'FindNextWord("Hello,  World! ", &start_idx, &end_idx);' results in start_idx == 8, end_idx == 14.
//
// Hint) Reuse the solution to the previous problem.
{
//    printf("str = [%s], *start = %d, *end = %d\n", str, *start, *end);        // if necessary, enable this line for debugging. (disable before submission)

    // TO DO: Find the start index of a word.
    //        Initialize *start to *end, and increase it until *start reaches the end of string ('\0') or a non-whitespace character.
    //        Use isspace() to decide whether a character is whitespace or not.
     
    printf("str = [%s], *start = %d, *end = %d\n", str, *start, *end);        // if necessary, enable this line for debugging. (disable before submission)

    // TO DO: Find the start index of a word.
    //        Initialize *start to *end, and increase it until *start reaches the end of string ('\0') or a non-whitespace character.
    //        Use isspace() to check whether a character is whitespace or not.
    // Hint) To increase *start, you need to use parentheses, as (*start)++.
    //*end = 0;
    for(int i=*start; *str !='\0'; i++){
        if(isspace(str[i] == 0)){
            break;
        }else{
            (*end)++;

        }
    }
    // TO DO: If there is no remaining word, report failure.
    //        (If the (*start)-th character is the null character, set *start and *end to -1 for safety and return FALSE.)
    if(str[*start] =='\0'){
        return FALSE;
    }
    //TO DO: Find the end index of the word.
    //       Initialize *end to *start + 1, and increase it until *end //reaches the end of string ('\0') or a whitespace character.
    *start = *end +1;
    *end += *end;
    return TRUE;
}

void DisplayWords(Word words[], int n)
{
    printf("%d words\n", n);
    for(int i = 0; i < n; i++)
        printf("word %3d: %d %d \"%s\"\n", i, words[i].start, words[i].end, words[i].word);
}

void AddWord(char *str, int start, int end)
// Add a word to the array 'words' and increase 'no_word'.
// e.g., after calling 'AddWord("Hello, World!", 7, 12, substring);',
// The 'words' array has a new element composed of (7, 12, "World") and 'no_word' is increased.
{
    // TO DO: fill the start and end fields of words[no_word] using the parameters
    for(int i = start; i< end; i++){
        *words[no_word].word = str[i];
         if(i == end -1){
            str[i+1] = '\0';
            break;
        }
    }
    no_word++;
    // TO DO: build a string with str[start] ~ str[end - 1] in words[no_word].word. words[no_word].word = str[strat~end-1]
    // TO DO: increase no_word.
}

void ShuffleWords(Word words[], int n)
// Shuffle the elements of the array 'words'.
{
    // TO DO: implement this function.
    //      for i from 0 to n,
    //          generate a random number j in range [0, n).
    //          exchange words[i] and words[j]
    char* tmep;
    int x , y;
    for(int i=0; i<n;  i++){
        x = rand() % n;
        y = rand() % n;
        tmep = words[x].word;
        *words[x].word = *words[y].word;
        *words[y].word = *tmep;
    }

}

void ConcatAllWords(Word words[], int n, char text[])
// Concatenate all words in 'words' into 'text'.
{
    text[0] = 0;
    for(int i = 0; i < n; i++){
        strcat(text, words[i].word);
        if(i < n - 1)
            strcat(text, " ");
    }
}
