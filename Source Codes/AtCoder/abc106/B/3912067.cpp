#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getYakusu(int n) {
	int rtn = 0;
	for(int i = 1; i <= sqrt(n)+1; i++) {
		if(n % i == 0) rtn++;
	}
	return rtn * 2;
}
int main() {
	const int max_n = 201;
	vector<int> a(max_n, 0);
	for(int i = 9; i < max_n; i+=2) {
		a[i] = getYakusu(i);
	}

	int n; cin >> n;
	int sum = 0;
	for(int i = 9; i <= n; i+=2) {
//		cout << "i=" << i << "   a[i]=" << a[i] << endl;
		if(a[i] == 8)  {
			sum++;
		}
	}
	cout << sum << endl;
}