#include <stdio.h>

int gcd (int num1, int num2)
{
	int rem, y;
	if(num2 !=0)
	{
    	int rem = num1 % num2; 
		num1 = num2;
		num2 = rem;
		y = gcd(num1, num2);
	}
	else
	{
		y = num1;
	}
	return y;
}
int main()
{
	int n1, n2;
	printf("Enter two numbers: ");
	scanf("%d %d", &n1, &n2);
	int res = gcd(n1, n2);
	printf("the result is: %d\n", res);
	return 0;
}