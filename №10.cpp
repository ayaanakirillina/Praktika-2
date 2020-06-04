/* 10.Напишите функцию, которая "сглаживает" значения двумерного массива.
Значение каждого элемента массива заполняется средним арифметическим соседних элементов.
Эта операция проводится до тех пор, пока все значения массива перестанут меняться. */

#include <iostream>

using namespace std;

void f(float **a, int n, int m)
{
	int i, j;
	float **b = new float *[n];
	for (i = 0; i < n; i++)
		b[i] = new float[m];
	for (i = 1; i <= n - 2; i++)
	{
		for (j = 1; j <= m - 2; j++)
			b[i][j] = (a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1]) / 8;
		b[i][0] = (a[i - 1][0] + a[i - 1][1] + a[i][1] + a[i + 1][0] + a[i + 1][1]) / 5;
		b[i][m - 1] = (a[i - 1][m - 2] + a[i - 1][m - 1] + a[i][m - 2] + a[i + 1][m - 2] + a[i + 1][m - 1]) / 5;
	}
	for (j = 1; j <= m - 2; j++)
	{
		b[0][j] = (a[0][j - 1] + a[0][j + 1] + a[1][j - 1] + a[1][j] + a[1][j + 1]) / 5;
		b[n - 1][j] = (a[n - 1][j - 1] + a[n - 1][j + 1] + a[n - 2][j - 1] + a[n - 2][j] + a[n - 2][j + 1]) / 5;
	}
	b[0][0] = (a[0][1] + a[1][0] + a[1][1]) / 3;
	b[0][m - 1] = (a[0][m - 2] + a[1][m - 2] + a[1][m - 1]) / 3;
	b[n - 1][0] = (a[n - 1][1] + a[n - 2][0] + a[n - 2][1]) / 3;
	b[n - 1][m - 1] = (a[n - 1][m - 2] + a[n - 2][m - 2] + a[n - 2][m - 1]) / 3;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			a[i][j] = b[i][j];
		delete (b[i]);
	}
	delete (b);
}
int g(float **a, int n, int m)
{
	float t = a[0][0];
	int i, j, s = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] != t)
			{
				s = 0;
				i = n;
				break;
			}
		}
	}
	return(s);
}
void q(float **a, int n, int m)
{
	while (g(a, n, m) == 0)
		f(a, n, m);
}
void main()
{
	int i, j, n, m;
	cin >> n >> m;
	float **a = new float *[n];
	for (i = 0; i < n; i++)
		a[i] = new float[m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cin >> a[i][j];
	}
	q(a, n, m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	system("pause");
}