#include <stdio.h>
int main (){
    
    float operand = 0.F, operand2 = 0.F; 
    char operator = 0;
    float result = 0.F;
    
    
    // read expressiokn
    printf("input a binary expression :");
    scanf("%f %c %f ",&operand, &operator, &operand2);
    // compute expression according to the operator
   switch (operator/*내가 사용할 casee*/) //using sitch statement 
   {
    case '+':
        result = operand + operand2;
        break;
    case '-':
        result = operand - operand2;
        break;
    case '*':
        result = operand * operand2;
        break;
    case '/':
        if(operand2 !=0.F)
        result = operand / operand2;
        break;
   }
   
   
   /* if(operator == '-'){ // if 문사용
        result = operand - operand2;
    }
    if(operator == '+'){
        result = operand + operand2;
    }
    if(operator == '*'){
        result = operand * operand2;
    }
    if(operator == '/' && operand2 !=0.F){
        result = operand / operand2;
    }
    */
    // display the result
    
    printf("%f %c %f = %f",operand, operator, operand2, result);

   return 0;
}