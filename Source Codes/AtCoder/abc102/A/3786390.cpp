#include<iostream>
using namespace std;

int main() {

	int n,i,ans;
	cin >> n;

	for (i = n; i <= (n*2)/2; i++) {
		if (i % 2 == 0 && i%n == 0) {
			ans = i;
			break;
		}
		else if (i == (n * 2) / 2) {
			ans = n * 2;
		}
	}

	cout << ans;

	return 0;
}