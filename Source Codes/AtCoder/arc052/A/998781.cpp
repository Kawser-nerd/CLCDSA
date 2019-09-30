#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

signed main() {
	string a;
	cin >> a;
	a += " ";
	for (int b = 0; b < a.length()-1; b++) {
		if (a[b] >= '0'&&a[b] <= '9') {
			if (a[b + 1] >= '0'&&a[b + 1] <= '9') {
				cout << a[b] << a[b + 1] << endl;
				return 0;
			}
			else {
				cout << a[b] << endl;
				return 0;
			}
		}
	}
}