#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n; cin >> n;
	vector<string> w(n);
	set<string> set_w;
	for(int i = 0; i < n; i++) {
		cin >> w[i];
		set_w.insert(w[i]);
	}

	if(set_w.size() != n) {
			cout << "No\n";
			return 0;
	}

	for(int i = 1; i < n; i++) {
		int end_loc = w[i-1].length() - 1;
		if(w[i-1][end_loc] != w[i][0]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}