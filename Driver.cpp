#include<iostream>
using namespace std;


int **createPascalTriangle(int n);
void displayPascalTriangle(int **ptr, int n);
void deallocatePascalTriangle(int **ptr, int n);


int main()
{
	int n;
	cout << "Enter the number of rows for pascal triangle: ";
	cin >> n;
	int **ptr = createPascalTriangle(n);
	displayPascalTriangle(ptr, n);
	deallocatePascalTriangle(ptr, n);
	return 0;
}


int **createPascalTriangle(int n)
{
	if (n < 0)
		return (int**)nullptr;
	int j = 0;
	int **ptr = new int *[n];
	for (int i = 0;i < n;i++)
		ptr[i] = new int[i+1];
	for (int i = 0;i < n;i++)
	{
		j = i + 1;
		for (int k = 0;k < j;k++)
		{
			if (k>0 && k<i)
				ptr[i][k] = ptr[i - 1][k] + ptr[i - 1][k - 1];
			else
				ptr[i][k] = 1;
		}
	}
	return ptr;
}


void displayPascalTriangle(int **ptr, int n)
{
	if (n > 0)
	{
		int j = 0;
		for (int i = 0;i < n;i++)
		{
			j = i + 1;
			for (int k = 0;k < j;k++)
			{
				cout << ptr[i][k] << "   ";
			}
			cout << '\n';
		}
	}
}

void deallocatePascalTriangle(int **ptr, int n)
{
	if (n > 0)
	{
		for (int i = 0;i < n;i++)
			delete[] ptr[i];
		delete[] ptr;
		ptr = 0;
	}
}