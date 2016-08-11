#include <stdio.h>

void select_sort(int arr[], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		int min = i;
		for(j = i+1; j < n; j++)
		{
			if(arr[min] > arr[j])
			{
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
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
	select_sort(arr, 5);
	return 0;
}