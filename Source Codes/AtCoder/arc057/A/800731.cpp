#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long int a, k, counter;
	cin >> a >> k;
	counter = 0;
	long long int limit = 2 * 1000000000000;

	//cout << a << "," << limit <<endl;
	if (k == 0) {
		cout << limit - a << endl;
	}

	else {

		long double aaa = (long double)(limit - a) / (long double)(k*a + 1);
		aaa = aaa*k + 1;
		cout << ceil(log(aaa) / log(k + 1) ) << endl;
	}
	return 0;
}