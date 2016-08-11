#include <stdio.h>

int main()
{
	int size, i;
	printf("Enter the size of array: ");
	scanf("%d", &size);
	int arr[size], arr1[size], arr2[size];
	arr1[0] = 1;
	arr2[size-1] = 1;
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i = 1; i < size; i++)
	{
		arr1[i] = arr1[i-1] * arr[i-1];
	}
	for(i = size-2; i >= 0; i--)
	{
		arr2[i] = arr2[i+1] * arr[i+1];
	}
	for(i = 0; i < size; i++)
	{
		printf("%d ", arr1[i] * arr2[i]);
	}
	printf("\n");
}