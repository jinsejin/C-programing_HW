#include <stdio.h>
#include <stdlib.h>
//irst mission
   // declare a structure to represent fractions
   // declare three fraction variables, fr1, fr2, and res 
   // read two fractions fr1 and fr2 from the user
   // multiply fr1 and fr2 into res
   // display result
/*Next mission:
   * write the following function
   Fraction MultiplyFraction(Fraction f1, Fraction f2);
   * simplify main() using MultiplyFraction()
   */
typedef struct{
    int a;
    int b;
}Fraction;
Fraction MultiplyFraction(Fraction f1, Fraction f2);
int main(){
    Fraction fr1;
    Fraction fr2;
    Fraction res;
    pritnf("fr1, fr2");
    scanf("%d %d",&fr1.a,&fr2.b);
    
    res.b= fr1.a * fr2.b;
    printf("multiply fr1 and fr2 into res %d",res.b);
    res = MultiplyFraction(fr1,fr2);
     printf("multiply fr1 and fr2 into res %d",res.b);


    return 0;
}
Fraction MultiplyFraction(Fraction f1, Fraction f2){
    Fraction result;
    result.b = f1.a * f2.b;
    return result;
}
//using pointer in structure
// sam1.x === (*ptr).x
// *ptr.x === *(ptr.x) != sam1.x // . is not allowed for a pointer variable
// for a structure variable, use '.' to access a field
// for a structure pointer, use '->' to access a field
