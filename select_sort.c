#include <stdio.h>

void selection_sort(char *a[], int n, int(*fp)(void *, void *))
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		int min = i;
		for(j = i+1; j <  n; j++)
		{
			if((*fp)(a[j], a[min]) < 0)
			{
				min = j;
			}
		}
		if(min != i)
		{
			swap(a, i, min);
		}
	}
}

void swap(char *a[], int i, int j)
{
	char *temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int strcmp(void *s, void *t)
{
	for(; *s == *t; s++,t++);
	return *s > *t;
}

int fltcmp(void *s, void *t)
{
	float a = atof(s);
	float b = atof(t);
	if(a > b)
		return 1;
	else
		return -1;
    return 0;
}

int main()
{
	char a[][] = {"HELLO", "WORLD", "HI"};
	selection_sort(a, 3, (*fp)(void *, void *)(strcmp));
	char b[][] = {"1.0", "5.43", ".012"};
	selection_sort(b, 3, (*fp)(void *, void *)(fltcmp));
}

