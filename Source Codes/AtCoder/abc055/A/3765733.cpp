#include <iostream>
using namespace std;

int main() {
	int N, x, y;

	cin >> N;
	x = 800 * N;
	y = N / 15 * 200;
	int res = x - y;

	cout << res << endl;
}