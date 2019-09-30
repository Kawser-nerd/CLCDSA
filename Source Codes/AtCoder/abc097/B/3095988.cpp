#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N;
	int K;
	int max = 0;

	cin >> N;

	for (int i = 1; i <= 100; i++)
	{
		for (int j = 2; j <= 100; j++)
		{
			K = (int)pow(i,j);
			if (K > N) {
				break;
			}
			if (K > max) {
				max = K;
			}
		}
	}

	cout << max << endl;

	return 0;
}