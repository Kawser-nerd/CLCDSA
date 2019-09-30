#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0;i < n;i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define pq priority_queue<int,vector<int>,greater<int>>
#define ll long long
//#define int long long

using namespace std;

typedef pair<int, int> pi;
int n, m, c[26];
string s;
int main() {
	cin >> s;
	rep(i, s.size()) {
		c[s[i] - 'a']++;
	}
	rep(i, 26) {
		if (c[i] == 0) {
			cout << char('a' + i) << endl;
			return 0;
		}
	}
	cout << "None" << endl;
	return 0;
}