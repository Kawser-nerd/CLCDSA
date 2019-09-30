#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
const int INF = 1000000; // ??????
int n,m,a[60],b[60],c[60],d[60];
int func(int id){
	int best = INT_MAX;
	int ans = -1;
	REP(j,m){
		int dist = abs(a[id] -c[j]) + abs(b[id] -d[j]);
		if(dist < best){
			best = dist;
			ans = j;
		}
	}
	return ans + 1;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	REP(i,n)cin >> a[i] >> b[i];
	REP(j,m)cin >> c[j] >> d[j];
	REP(i,n)cout << func(i) << endl;
	return 0;
}