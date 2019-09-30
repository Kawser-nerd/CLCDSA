//????????????????????????????????????N = 2??Max, Min??????????
//???N-1?????{a_i >= 0, all i} ??? {a_i <= 0, all i}???????????N = 2???????????

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
#define int long long
using namespace std;
typedef pair<int, int> P;

int n;
int a[50];
vector<P> ans;

void solve1() {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			a[i + 1] += a[i];
			ans.push_back(P(i, i + 1));
		}
	}
}

void solve2() {
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > a[i + 1]) {
			a[i] += a[i + 1];
			ans.push_back(P(i + 1, i));
		}
	}
}

void addMax() {
	int i, id = 0;
	
	for (i = 1; i < n; i++) {
		if (a[id] < a[i]) id = i;
	}
	
	for (i = 0; i < n; i++) {
		if (i == id) continue;
		a[i] += a[id];
		ans.push_back(P(id, i));
	}
}

void addMin() {
	int i, id = 0;
	
	for (i = 1; i < n; i++) {
		if (a[id] > a[i]) id = i;
	}
	
	for (i = 0; i < n; i++) {
		if (i == id) continue;
		a[i] += a[id];
		ans.push_back(P(id, i));
	}
}

signed main()
{
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i];
	
	int Max = a[0];
	int Min = a[0];
	for (i = 1; i < n; i++) {
		if (Max < a[i]) Max = a[i];
		if (Min > a[i]) Min = a[i];
	}
	
	if (Min >= 0) { solve1(); }
	else if (Max <= 0) { solve2(); }
	else if (Max >= -Min) { addMax(); solve1(); }
	else { addMin(); solve2(); }
	
	cout << ans.size() << endl;
	for (i = 0; i < ans.size(); i++) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}
	
	/*cout << "debug" << endl;
	for (i = 0; i < n; i++) {
		cout << a[i] << endl;
	}*/
	return 0;
}