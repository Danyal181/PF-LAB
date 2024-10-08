#include <stdio.h>


int main()
{
	int n;
	int i;
	int not_prime;
	
	printf("Enter the number you want to check: \n");
    scanf("%d", &n);


    for (i=2; i<n; i++)
    {
    	if (n % i == 0)
    	{
    		not_prime = 1;
    		
		}
	}
	if (not_prime == 1)
	printf("It is not a prime number \n ");
	else
	printf("It is a prime number \n ");
}
	     