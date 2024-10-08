#include <stdio.h>

int main()

{
   int num,count;
   printf("Enter a number ");
   scanf("%d",&num);
   if(num>=10 || num<=-10){
       printf("is a multiple digits number");
   }
   else{
       
       printf("is a single digit number");
   }
    return 0;
}