#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
typedef pair<int, int> P;

int p[29], ans = 0,a[29], b[29];
const int nmax = 8;
bool graph[nmax][nmax];
bool pairCompare(const P& firstElof, const P& secondElof)
{
	return firstElof.second < secondElof.second;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	scanf("%d %d", &N ,&M);

	vector<P> warsP(M);
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		warsP[i] = P(a,b);
	}
	sort(warsP.begin(), warsP.end(), pairCompare);
	int ans = 1;
	int brk = 0;
	REP (i, warsP.size()) {
		int x = warsP[brk].second;
		if (x <= warsP[i].first) {
			brk = i;
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}