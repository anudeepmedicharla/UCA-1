#include <stdio.h>

int binary_search(int arr[], int start, int end, int num)
{
	int mid = (start + end)/2;
	if(start <= end)
	{
		if(num < arr[mid])
		{ 
			binary_search(arr, start, mid-1, num);
		}
		else if(num > arr[mid])
		{
			binary_search(arr, mid+1, end, num);
		}
		else if(num == arr[mid])
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}
int main()
{
	int arr[5] = {2, 6, 8, 50, 67};
	int num, i, j, mid, start, end, flag = 0;
	printf("enter the num: ");
	scanf("%d", &num);
	start = 0, end = 4;
	int res = binary_search(arr, start, end, num);
	if(res == 1)
		printf("Number found\n");
	else
		printf("Number not found\n");
	return 0;
}