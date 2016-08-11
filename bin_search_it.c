#include <stdio.h>
int main()
{
	int arr[5] = {2, 6, 8, 50, 67};
	int num, i, j, mid, start, end, flag = 0;
	printf("enter the num: ");
	scanf("%d", &num);
	start = 0, end = 4;
	
	while(start <= end)
	{
		mid = (start + end)/2;
		if(num < arr[mid])
		{ 
			end = mid-1;
		}
		else if(num > arr[mid])
		{
			start = mid + 1;
		}
		else if(num == arr[mid])
		{
			printf("Number found\n");
			flag = 1;
			break;

		}	
	}
	if(flag == 0)
	{
		printf("Number not found\n");
	} 
	return 0;
} 