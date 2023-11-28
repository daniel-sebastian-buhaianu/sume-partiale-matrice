#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "n = "; cin >> n;
	int a[n][n], i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = 1;
		}
	}
	int s[n][n];
	s[0][0] = a[0][0];
	for (j = 1; j < n; j++)
	{
		s[0][j] = s[0][j-1] + a[0][j];
	}
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j == 0)
			{
				s[i][j] = s[i-1][j] + a[i][j];
			}
			else
			{
				s[i][j] = s[i-1][j]
				          + s[i][j-1]
					  - s[i-1][j-1]
					  + a[i][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << s[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}

