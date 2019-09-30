#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int N;
	int i, j, k;
	int P[10000];
	int num = 0;

	cin >> N;
	
	for (i = 3;i <= 55555;i += 2)
	{
		k = 0;
		for (j = 3;j <= sqrt(i);j += 2)
		{
			if ((i%j == 0))
			{
				k = 1;
				break;
			}
		}

		if (k == 0&&(i%5==1))
			P[num++] = i;

		if (num >= N) {
			break;
		}
	}
	cout << P[0];
	for (int i = 1; i < N; i++)
	{
		cout << " " << P[i];
	}
	cout << endl;

	return 0;
}