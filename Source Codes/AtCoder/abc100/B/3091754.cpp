#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int D, N;
	
	cin >> D >> N;

	D = pow(100, D);

	if (N == 100) {
		N++;
	}

	cout << D * N << endl;

	return 0;
}