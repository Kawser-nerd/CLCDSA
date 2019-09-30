#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
signed main() {
	vector<string>v; int n, l; cin >> n >> l;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(s);
	}sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)cout << v[i]; cout << endl;
}