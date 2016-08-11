#include <stdio.h>
int main(int argc, char *argv[])
{
	int sum = 0, i;
	for(i = 1; i < argc; i++)
	{
		sum = sum + atoi(argv[i]);
	}
	printf("%d\n", sum);
}