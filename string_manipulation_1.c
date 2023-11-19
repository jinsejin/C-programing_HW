#include <stdio.h>
#include <string.h>

int my_strlen(char str[]);
char* my_strcpy(char dest[], char src[]);
char* my_strcat(char dest[], char src[]);
int my_strcmp(char dest[], char src[]);

int main()
{
    char str1[] = "HELLO";
    char str2[] = "ABCDE";
    char str3[256] = "";

    printf("my_strlen(str1) = %d\n", my_strlen(str1));

    my_strcpy(str3, str1);
    printf("str3 = %s\n", str3);


    printf("my_strcmp(str1, str3) = %d\n", my_strcmp(str1, str3));
    printf("my_strcmp(str1, str2) = %d\n", my_strcmp(str1, str2));
    printf("my_strcmp(str2, str1) = %d\n", my_strcmp(str2, str1));

    my_strcat(str3, str2);
    printf("str3 = %s\n", str3);

    return 0;
}

int my_strlen(char str[])
{
    int i = 0;
    while(str[i] != 0)
        i++;

    return i;
}

char* my_strcpy(char dest[], char src[])
{
    int i = 0;
    for(i = 0; src[i] != 0; i++)
        dest[i] = src[i];

    dest[i] = 0;
    
    return dest;
}

char* my_strcat(char dest[], char src[])
{
    //dest == "hello" i+5;
    //src ="abcdef"
    // using pointer!
    /*
    char *d = dest;
    while(*d != 0)
        d++;
    while(*src != 0)
        *(d++) = *(src++);
    */
   // using function
   my_strcpy(dest+ strlen(dest), src);

    return dest;
}

int my_strcmp(char str1[], char str2[])
{
    int i =0;
    for(i=0; str1[i] == str2[i] && str1[i] != 0; i++){}
    return (int)str1[i] - (int)str2[i];
}
/*
String length
size_t strlen( const char* str );

String copy
char* strcpy( char* dest, const char* src );
char *strncpy( char *dest, const char *src, size_t count );
errno_t strcpy_s( char *dest, rsize_t destsz, const char *src );

String concatenation
char *strcat( char *dest, const char *src );
char *strncat( char *dest, const char *src, size_t count);
errno_t strcat_s(char *dest, rsize_t destsz, const char *src);

String comparison
int strcmp( const char *lhs, const char *rhs );
int strncmp( const char *lhs, const char *rhs, size_t count );



*/