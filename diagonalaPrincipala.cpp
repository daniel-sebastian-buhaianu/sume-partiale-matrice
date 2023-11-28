#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cout << "n = "; cin >> n;
	int i, j, a[n][n];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = 1;
		}
	}
	int s[n][n];
	memset(s, 0, sizeof(s));
	for (j = n-2; j >= 0; j--)
	{
		s[0][j] = s[0][j+1] + a[0][j+1];
	}
	for (i = 1; i < n; i++)
	{
		for (j = n-1; j >= 0; j--)
		{
			if (j+1 == n)
			{
				s[i][j] = s[i-1][j-1];
			}
			else if (j == 0)
			{
				s[i][j] = s[i][j+1]
				          + a[i][j+1]
					  + a[i-1][j];
			}
			else
			{
				s[i][j] = s[i][j+1]
				          + s[i-1][j-1]
					  - s[i-1][j]
					  + a[i][j+1];
			}
		}
	}
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

