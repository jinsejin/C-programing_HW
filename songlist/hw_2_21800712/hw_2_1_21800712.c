#include <stdio.h>

int main(void) {
  char name[100] ;              //product name (use string문자열?)
  double shipping_charge =0.0;   // shippinng charge
  double price =0.0;             //unit price
  int quantity=0;               //quantity
  double total_price=0.0;        //total price

  //read the name, shopping chage, unit price,quanity and shipping charge, and then display the total price.
  printf("Item name:");
  scanf("%s",name);
  
  printf("Unit price:");
  scanf("%lf",&price);
  
  printf("Quantuty:");
  scanf("%d",&quantity);
  
  printf("Shipping charge:");
  scanf("%lf",&shipping_charge);
  //make a calcluation total_price.
  total_price = price * quantity + shipping_charge;
  //display the name, unit price, quantity,shipping charge and then total_price
  printf("%s: $%.2lf * %d + $%.2lf = $%.2lf",name,price,quantity,shipping_charge,total_price);

  return 0;
}
//Battlecruizer: $200000000.00 * 12 + $5000.00 = $2400005000.0