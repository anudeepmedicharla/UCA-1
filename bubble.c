#include <stdio.h>

int main()
{
	int size, i, j, k, l;
	printf("ENTER THE SIZE: ");
	scanf("%d",&size);
	int num[size];
	printf("ENTER ELEMENTS: ");
	for(i=0;i<size;i++)
	{
		scanf("%d", &num[i]);
	}
	for(k=0;k<size;k++)
	{
		for (j = 0; j < size-k-1; ++j)
		{
			if(num[j] > num[j+1])
			{
				int temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
	for( l=0;l<size;l++)
	{
		printf("%d ",num[l]);
	}
	printf("\n");
	return 0;
}