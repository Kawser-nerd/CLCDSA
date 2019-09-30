#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
map <pair <pair <int, int>, int>, ll> mp;

ll func(int A, int B, int K){
	if(A == 0 || B == 0 || K == 0) return 0;
	if(A == 1 && B == 1 && K == 1) return 1;
	
	pair <pair <int, int>, int> st = make_pair(make_pair(A, B), K);
	if(mp.find(st) != mp.end()) return mp[st];
	
	ll ans = 0;
	
	int i,j;
	REP(i,2) REP(j,2){
		int k = (i & j);
		if(i >= A || j >= B || k >= K) continue;
		ans += func((A-i+1)/2, (B-j+1)/2, (K-k+1)/2);
	}
	
	return mp[st] = ans;
}

void main2(void){
	int A,B,K;
	cin >> A >> B >> K;
	mp.clear();
	ll ans = func(A, B, K);
	cout << ans << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
