#include <iostream>
#include <vector>
using namespace std;

int main() {
	const int n = 11;
	vector<int> l(n, 0);
	for(int i = 0; i < 3; i++) {
		int inp; cin >> inp;
		l[inp]++;
	}
	int ans = 999;
	for(int i = 1; i < n; i++) {
		if(l[i] == 1 || l[i] == 3) ans = i;
	}
	cout << ans << endl;
}