#include <stdio.h>


void merge(int arr[], int beg, int mid, int end)
{
	int i = beg;
	int j = mid + 1, k = 0, brr[10];
	while(i <= mid && j <= end)
	{
		if(arr[i] < arr[j])
		{
			brr[k] = arr[i];
			i++;
		}
		else
		{
			brr[k] = arr[j];
			j++;
		}
		k++;
	}
	if(i > mid)
	{
		while(j <= end)
		{
			brr[k] = arr[j];
			j++;
			k++;
		}
	}
	if(j > end)
	{
		while(i <= mid)
		{
			brr[k] = arr[i];
			k++;
			i++;
		}
	}
	for(i = beg; i <= end; i++)
	{
		arr[i] = brr[i];
	}
}
void merge_sort(int arr[], int beg, int end)
{
	int mid;
	if(beg < end)
	{

		mid = (beg + end)/2;
		merge_sort(arr, beg, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, beg, mid, end);
	}
}

void main()
{
	int arr[10];
	int n, i, j, beg, end;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	printf("Enter the elements of array: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	beg = 0;
	end = n-1;
	merge_sort(arr, beg, end);
	printf("Sorted elements of array: ");
	for(i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
