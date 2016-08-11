#include <stdio.h>

static char buffer[1000];
static char *current = buffer;

char *myalloc(int x)
{
	if(current + x > buffer + 1000)
	{
		printf("NOT SUFFICIENT MEMEORY\n");
	}
	else
	{
		char *t = current;
		current = current + x;
		return t;
	}
}

void myfree(int n)
{
	if(current - n < buffer)
	{
		printf("MEMEORY NOT IN SCOPE\n");
	}
	else
	{
		current = current - n;
		printf("CURRENT POSTION IS: %p\n", current);
	}
}
int main()
{
	char *s;
	s = myalloc(20);
	printf("%p\n",s);
	s = myalloc(10);
	printf("%p\n",s);
	s = myalloc(30);
	printf("%p\n",s);
	myfree(30);
	printf("%p\n",current);
	myfree(10);
	printf("%p\n",current);
	myfree(20);
	printf("%p\n",current);
	return 0;
}