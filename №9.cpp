//Напишите функцию, которая определяет L2 норму погрешности по двум заданным двумерным массивам.
#include<iostream>
#include<math.h>
using namespace std;
float L2(float **a, float **b, int n, int m)
{
	int i, j;
	float s = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			s += (a[i][j] - b[i][j])*(a[i][j] - b[i][j]);
	}
	return (sqrt(s));
}
void main()
{
	int i, j, n, m;
	cin >> n >> m;
	float **a = new float*[n], **b = new float*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new float[m];
		b[i] = new float[m];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cin >> a[i][j];
	}
	cout << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cin >> b[i][j];
	}
	cout << endl << L2(a, b, n, m) << endl;
	system("pause");
}