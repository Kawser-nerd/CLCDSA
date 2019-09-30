#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	double sum = 0.0;
	for(int i = 1; i <= n; i++) {
		sum += 10000 * i * (1/(double)n);
	}
	cout << int(sum) << endl;
}