/*
    Read an integer k in range [1, 100].
    Read float numbers from the user until the user types -999, keeping the largest k numbers in an array.
    Display the k-largest numbers.

    Example) Keeping 5 largest numbers, the user inputs 1, 9, 2, 8, 3, 7, 4, 6, 5, -999
        Choose k in range [1, 100]: 5
        array before insertion: no element.
        Input a float number (EOF to finish): 1
        position to insert = 0
        array after shift: 0.00                     // the element at the insertion position (0) is a dummy value
        array before insertion: 1.00                // 1 was placed at position 0
        Input a float number (EOF to finish): 9
        position to insert = 0
        array after shift: 1.00 1.00                // the number after the insertion position (0) was shifted right
        array before insertion: 9.00 1.00           // 9 was placed at position 0
        Input a float number (EOF to finish): 2
        position to insert = 1
        array after shift: 9.00 1.00 1.00           // the number after the insertion position (1) was shifted right
        array before insertion: 9.00 2.00 1.00      // 2 was placed at position 1
        Input a float number (EOF to finish): 8
        position to insert = 1
        array after shift: 9.00 2.00 2.00 1.00              // the numbers after the insertion position (1) were shifted right
        array before insertion: 9.00 8.00 2.00 1.00         // 8 was placed at position 1
        Input a float number (EOF to finish): 3
        position to insert = 2
        array after shift: 9.00 8.00 2.00 2.00 1.00         // the numbers after the insertion position (w) were shifted right
        array before insertion: 9.00 8.00 3.00 2.00 1.00    // 3 was place at position 2
        Input a float number (EOF to finish): 7
        position to insert = 2
        array after shift: 9.00 8.00 3.00 3.00 2.00 
        array before insertion: 9.00 8.00 7.00 3.00 2.00 
        Input a float number (EOF to finish): 4
        position to insert = 3
        array after shift: 9.00 8.00 7.00 3.00 3.00
        array before insertion: 9.00 8.00 7.00 4.00 3.00
        Input a float number (EOF to finish): 6
        position to insert = 3
        array after shift: 9.00 8.00 7.00 4.00 4.00
        array before insertion: 9.00 8.00 7.00 6.00 4.00
        Input a float number (EOF to finish): 5
        position to insert = 4
        array after shift: 9.00 8.00 7.00 6.00 4.00
        array before insertion: 9.00 8.00 7.00 6.00 5.00
        Input a float number (EOF to finish): -999
        Top-5 numbers are: 9.00 8.00 7.00 6.00 5.00         // final result

    Example) Keeping 3 largest numbers, the user inputs 1, 4, 2, 3, 7, 8, 2, 8, -999
        Choose k in range [1, 100]: 3
        array before insertion: no element.
        Input a float number (EOF to finish): 1
        position to insert = 0
        array after shift: 0.00 
        array before insertion: 1.00 
        Input a float number (EOF to finish): 4
        position to insert = 0
        array after shift: 1.00 1.00 
        array before insertion: 4.00 1.00 
        Input a float number (EOF to finish): 2
        position to insert = 1
        array after shift: 4.00 1.00 1.00 
        array before insertion: 4.00 2.00 1.00 
        Input a float number (EOF to finish): 3
        position to insert = 1
        array after shift: 4.00 2.00 2.00 
        array before insertion: 4.00 3.00 2.00 
        Input a float number (EOF to finish): 7
        position to insert = 0
        array after shift: 4.00 4.00 3.00 
        array before insertion: 7.00 4.00 3.00 
        Input a float number (EOF to finish): 8
        position to insert = 0
        array after shift: 7.00 7.00 4.00 
        array before insertion: 8.00 7.00 4.00 
        Input a float number (EOF to finish): 2
        position to insert = 3
        array after shift: 8.00 7.00 4.00 
        array before insertion: 8.00 7.00 4.00 
        Input a float number (EOF to finish): 8
        position to insert = 1
        array after shift: 8.00 7.00 7.00 
        array before insertion: 8.00 8.00 7.00 
        Input a float number (EOF to finish): -999
        Top-3 numbers are: 8.00 8.00 7.00 



*/

#include <stdio.h>

#define BUFFER_SIZE 100     // k should not exceed BUFFER_SIZE

void DisplayArray(float array[], int size);

int main()
{
    float largest[BUFFER_SIZE] = { 0.F };
    int k = 0;          // number of data to keep
    int n = 0;          // number of data in array (n <= k)
    float x = 0;        // input data
    int p=0;
    // read k from the user
    printf("Choose k in range [1, 100]: ");
    scanf("%d", &k);

    // repeat until the user types EOF (use an infinite loop)
    while(1){
        // for debugging, display array
        printf("array before insertion: ");
        DisplayArray(largest, n);

        // read a float number
        printf("Input a float number (EOF to finish): ");
        scanf("%f", &x);

        // if the input number is -999, break the loop
        if(x == -999)
            break;    
        // TO DO: find position to insert the input number
        // (to make a room for the input number, shift all numbers smaller than the input number one step right)
        
        // after modifying code!
        //find position to insert the input number
        int temp=0;               
        for(int j=0; j<n; j++){
            for(int i=0; i<j; i++){
                if(largest[i] < largest[j]){
                    temp = largest[j];
                    largest[j] = largest[i];
                    largest[i] = temp;
                    p=n-j;
                }
            }     
        }
        /* before modifying code
        for(int j=0; j<n; j++){
            for(int i=0; i<j; i++){
                if(largest[i] > largest[j]){
                    temp = largest[j];
                    largest[j] = largest[i];
                    largest[i] = temp;
                    p=n-j;
                }
            }     
        }
        */
        printf("position to insert = %d\n", p);         // declare a variable p above
        // TO DO: if n is smaller than k, increase n
        if(n < k){
            //largest[n-1] = x;
            n++;  
        }
        // for debugging, display array
        printf("array after shift: ");
        DisplayArray(largest, n);
        // TO DO: if p is smaller than k, insert the input into the array
        if(p<k){
            largest[n-1] = x;
        }
    }

    printf("Top-%d numbers are: ", k);
    DisplayArray(largest, n);

    return 0;
}

void DisplayArray(float array[], int size)
{
    if(size == 0){
        printf("no element.\n");
    } else {
        for(int i = 0; i < size; i++)
            printf("%.2f ", array[i]);
        printf("\n");
    }
}
/*
    for(int i=0; i<=n; i++)
    { 
        if(s==0)
            largest[n-1] = x;    
        else
            largest[n] = x;
    }
    if k=3 >> n = 1 시작
    k-n == 2
    n =2
    k =1
    n3
    k=0  
*/
