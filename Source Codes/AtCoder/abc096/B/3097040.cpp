#include <iostream>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	long long N[3], K;
	for (int i = 0; i < 3; i++)
	{
		cin >> N[i];
	}
	cin >> K;

	sort(N, N + 3);
	N[2] *= pow(2,K);

	cout << accumulate(N, N + 3, 0) << endl;

	return 0;
}