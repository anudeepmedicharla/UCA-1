#include <stdio.h>
int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d", &n);
	if(n < 0)
	{
		n *= -1;
	}
	if(n & (n-1))
		printf("Number is not some power of 2\n");
	else
		printf("Number is some power of 2\n");
	return 0;
}