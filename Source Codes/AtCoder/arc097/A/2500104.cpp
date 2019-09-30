#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string s;
int n, k;
vector<string> v;
void solve() {
	n = s.length();
	string tmp;
	for (int i = 0; i<n; i++) {
		tmp.clear();
		for (int j = 0; j<5 && i + j<n; j++) {
			tmp.push_back(s[i + j]);
			//	cout << tmp << endl;
			v.push_back(tmp);
		}
	}
	sort(v.begin(), v.end());
	unique(v.begin(), v.end());
	cout << v[k - 1] << endl;
}
int main() {
	cin >> s >> k;
	solve();
	return 0;
}