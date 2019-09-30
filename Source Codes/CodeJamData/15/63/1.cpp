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

int N;
ll F;
char buf[500010];
string s;
pair <ll, int> p[500010];
int sum[500010];

int ans;
ll bestx,besty; // best ans is bestx / besty

ll gcd(ll x, ll y){
	return x ? gcd(y%x, x) : y;
}

bool smaller(ll x, ll y, ll x2, ll y2){ // x / y < x2 / y2
	// cerr << x << ' ' << y << ' ' << x2 << ' ' << y2 << endl;
	if(x / y < x2 / y2) return true;
	if(x / y > x2 / y2) return false;
	x %= y; x2 %= y2;
	if(x2 == 0) return false;
	if(x == 0) return true;
	return smaller(y2, x2, y, x);
}

void check(int p, int q){ // cerr << p << ' ' << q << endl;
	if(p > q) swap(p, q);
	ll dx = q - p;
	ll dy = sum[q] - sum[p];
	
	ll x = dy * 1000000 - dx * F;
	if(x < 0) x = -x;
	ll y = dx * 1000000;
	ll g = gcd(x, y);
	x /= g; y /= g;
	
	if(smaller(x, y, bestx, besty)){
		bestx = x;
		besty = y;
		ans = p;
	} else if(!smaller(bestx, besty, x, y) && p < ans){
		ans = p;
	}
}
	
void main2(void){
	int i;
	
	double tmp;
	cin >> N >> tmp;
	F = (int)(tmp * 1000000.0 + 0.5);
	scanf("%s", buf);
	s = buf;
	
	REP(i,N) sum[i+1] = sum[i] + ((s[i] == '1') ? 1 : 0);
	REP(i,N+1) p[i] = make_pair((ll)sum[i] * 1000000ll - (ll)i * (ll)F, i);
	sort(p, p+N+1);
	
	ans = (1<<29);
	bestx = 2; besty = 1;
	REP(i,N) check(p[i].second, p[i+1].second);
	
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
