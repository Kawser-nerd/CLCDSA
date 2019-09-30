#include <iostream>

using namespace std;
int main(void)
{
	int a, b;
	cin >> a >> b;
	
	int *c,*d,*e;
	c = new int[b];
	d = new int[b];
	e = new int[b];
	for (int i = 0; i < b ; i++)
	{
		cin >> c[i] >> d[i] >> e[i];
	}


	int *array;
	array = new int[a];
	for (int j =0 ; j <b ; j++)
	{
		for (int k = c[j] - 1; k < d[j]; k++)
		{
			array[k] = e[j];
		}
	}

	for (int m = 0; m < a; m++)
	{
		cout << array[m] << endl;
	}


		 
	return 0;

	}