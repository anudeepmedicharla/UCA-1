#include <stdio.h>
#include <sys/time.h>

long int get_time()
{
	struct timeval t;
	gettimeofday(&t,NULL);
	long int time1 = t.tv_sec * 1000000 + t.tv_usec;
	return time1;
}
void sort(int ar[], int n)
{
	int i, j, k;
	for(k = 0; k < n; k++)
	{
		for (j = 0; j < n-k-1; ++j)
		{
			if(ar[j] > ar[j+1])
			{
				int temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
			}
		}
	}
} 

int main()
{
	int a[8000], b[16000];
	int k = 16000, l = 8000, i, j;
	for(i = 0; i < 8000; i++)
	{
		a[i] = l--;
	}
	for(i = 0; i < 16000; i++)
	{
		b[i] = k--;
	}
	long int abeg = get_time();
	sort(a, 8000);
	long int aend = get_time();
	long int t1 = aend - abeg;
	long int bbeg = get_time();
	sort(b, 16000);
	long int bend = get_time();
	long int t2 = bend - bbeg;
	double ratio = (double)t2/(double)t1;
	printf("THE RATIO IS: %lf\n", ratio);
	return 0;
}
