#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, k = 0;
	cout<<"Enter the number of strings: ";
	cin>>n;
	string arr[n], arr1[n], arr2[n];
	int flag[n];
	cout<<"Enter the srings: ";
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
		arr1[i] = arr[i];
		flag[i] = 0;
	}
	 //arr2[0] = arr[0];
	//flag[0] = 1;
	for(int i = 0; i < n; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}

	for(int i = 0; i < n ;i++)
	{
		//
		if(flag[i] == 0)
		{
			arr2[k++] = arr1[i];	
			for(int j = i + 1; j < n; j++)
			{
				if(arr[i] == arr[j])
				{
					arr2[k++] = arr1[j];
					flag[j] = 1;
				}
			}
		}
		else
		{
			continue;
		}	
	}
	for(int i = 0; i < n; i++)
	{
		cout<<arr2[i]<<" ";
	}
	return 0;
}