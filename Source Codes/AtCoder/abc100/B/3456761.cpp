#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int D, N;
    cin >> D >> N;

	int x = pow(100, D);

	cout << x * (N == 100 ? 101 : N) << endl;
}