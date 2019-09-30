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

int N,K;
ll s[1010];
ll a[1010];

bool check(ll M, int g, ll target){
	int i,j;
	
	ll low = 0;
	REP(i,K) low += a[i];
	
	ll high = low;
	REP(i,K) if(i != g){
		ll tmp = 0;
		for(j=i;j<N;j+=K) tmp = max(tmp, a[j]);
		high += M - tmp;
	}
	
	if(high - low >= K) return true;
	for(ll x=low;x<=high;x++) if(x % K == target) return true;
	return false;
}

void main2(void){
	int i,j;
	
	cin >> N >> K;
	REP(i,N-K+1) cin >> s[i];
	
	REP(i,N){
		if(i < K){
			a[i] = 0;
		} else {
			a[i] = a[i-K] + s[i-K+1] - s[i-K];
		}
	}
	
	REP(i,K){
		ll small = 0;
		for(j=i;j<N;j+=K) small = min(small, a[j]);
		for(j=i;j<N;j+=K) a[j] -= small;
	}
	
	ll target = s[0] % K;
	if(target < 0) target += K;
	
//	REP(i,N) cout << a[i] << ' ';
//	cout << endl;
//	cout << target << endl;
	
	ll tmp = 0;
	REP(i,N) tmp = max(tmp, a[i]);
	ll low = tmp - 1, high = tmp + K;
	
	while(high - low > 1){
		ll mid = (low + high) / 2;
		bool good = false;
		REP(i,K) if(check(mid, i, target)) good = true;
		if(good) high = mid; else low = mid;
	}
	
	cout << high << endl;
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
