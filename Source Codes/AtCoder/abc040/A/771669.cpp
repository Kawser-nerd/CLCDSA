#include <iostream>
#include <string>
#include <deque>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
	int n, x;

	cin >> n >> x;

	if (n - x < x - 1) {
		cout << n - x;
	} else {
		cout << x - 1;
	}
	cout << endl;

	return 0;
}