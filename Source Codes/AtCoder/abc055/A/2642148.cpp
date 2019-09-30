#include <iostream>
using namespace std;

int main() {
	int N, x, y;
	cin >> N;
	y = N / 15 * 200;
	x = N * 800;
	cout << x - y << endl;
	return 0;
}