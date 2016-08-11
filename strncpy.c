#include <stdio.h> 
void strncpy1(char *s, char *t, int num)
{
	int i;
	for(i = 0;i < num; i++)
	{
		*s++ = *t++;
	}
	*s++ = '\0';
}
int main()
{
	char str[] = "Hello";
	char str1[] = "Hello";
	int n = 3;
	strncpy1(str, str1, n);
	puts(str);
}