#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
using namespace std;

int n, k;
map<int, int> cnts;

signed main()
{
	int i;
	
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (cnts.find(a) == cnts.end()) cnts[a] = 0;
		cnts[a]++;
	}
	
	int type = 0;
	vector<int> v;
	for (map<int, int>::iterator it = cnts.begin(); it != cnts.end(); it++) {
		v.push_back(it->second);
		type++;
	}
	
	if (type <= k) { cout << 0 << endl; return 0; }
	
	sort(v.begin(), v.end());
	int ans = 0;
	for (i = 0; i < type - k; i++) { ans += v[i]; }
	cout << ans << endl;
	return 0;
}