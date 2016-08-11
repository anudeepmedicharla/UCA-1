#include <stdio.h>

void insert_sort(int arr[], int n)
{
	int i, j, hole, value;
	for(i = 1; i < n; i++)
	{
		value = arr[i];
		hole = i;
		while(hole > 0 && arr[hole - 1] > value)
		{
			arr[hole] = arr[hole-1];
			hole = hole-1;
		}
		arr[hole] = value;
	}
	for(i = 0; i < n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {5, 4, 3, 2, 1};
	insert_sort(arr, 5);
	return 0;
}