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

#define MAX 1000010
int sign[MAX];
int minp[MAX];

void pre(void){
	int i,j;
	
	for(i=2;i<MAX;i++) minp[i] = i;
	for(i=2;i<MAX;i++) if(minp[i] == i) for(j=i;j<MAX;j+=i) minp[j] = min(minp[j], i);
	
	sign[1] = 1;
	for(i=2;i<MAX;i++){
		int n = i;
		int p = minp[n];
		if((n / p) % p == 0){
			sign[n] = 0;
		} else {
			sign[n] = -sign[n/p];
		}
	}
}

ll func2(ll X, ll D){
	// count (a, b) s.t. 1 <= a <= X, 1 <= b <= X, a^2 + b^2 <= D
	
	ll d;
	for(d=1;;d++) if(d*d > D) break;
	X = min(X, d-1);
	
	ll ans = 0;
	ll y = X;
	for(ll x=1;x<=X;x++){
		while(x*x + y*y > D) y--;
		ans += y;
	}
	
	return ans;
}

ll func(ll X, ll D){
	// count (a, b) s.t. 1 <= a <= X, 1 <= b <= X, a^2 + b^2 <= D, gcd(a, b) = 1
	
	ll ans = 0;
	for(ll d=1;d*d<=D;d++) if(sign[d] != 0 && X >= d) ans += func2(X/d, D/d/d) * sign[d];
	return ans;
}

void main2(void){
	int i;
	
	ll N,R;
	cin >> N >> R;
	
	ll ans = func(N-1, 999999999999ll / R / R) + 2;
	cout << ans << endl;
}

int main(void){
	int TC,tc;
	pre();
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
