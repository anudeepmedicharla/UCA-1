#include <iostream>
using namespace std;

int main()
{
	int zrows = 0, zcols = 0, row, col;
	cout << "Enter the number of rows and columns:  ";
	cin >> row >> col;
	int mat[row][col];
	////////// INPUT THE ARRAY/////////////////
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> mat[i][j];
		}
	}
	////////////FIND ROWS AND COLS WITH ZERO IN THEM//////////////////////
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(mat[i][j] == 0)
			{
				zrows = zrows | (1 << i);
				zcols = zcols | (1 << j);
			}
		}
	}
	////////////////MAKING ROW WITH 0 WHOLE ZERO/////////////////////////
	for(int i = 0; i < row; i++)
	{
		if((zrows & (1 << i)) != 0)
		{
			for(int j = 0; j < col; j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	////////////////////////////MAKING THAT COLUMN WHOLE AS ZERO////////////////
	for(int i = 0; i < row; i++)
	{
		if((zcols & (1 << i)) != 0)
		{
			for(int j = 0; j < col; j++)
			{
				mat[j][i] = 0;
			}
		}
	}
	//////////////////////////////PRINT THE ARRAY///////////////////////////////
	cout<<"THE ARRAY ELEMENTS ARE: \n";
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout << mat[i][j]<<"\t";
		}
		cout << endl;
	}
	return 0;
}


