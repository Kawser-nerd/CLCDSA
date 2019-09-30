#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

LL reverse(LL x){
	LL y = 0;
	while(x){
		y = 10*y + x%10;
		x /= 10;
	}
	return y;
}

int len(LL x){
	int r = 0;
	while(x){
		++r;
		x /= 10;
	}
	return r;
}

LL solve(LL x){
	if(x < 10) return x;
	if(x%10 == 0) return solve(x-1) + 1;
	int d = (len(x) + 1) / 2;
	LL y = x;
	FWD(i,0,d) y /= 10;
	FWD(i,0,d) y *= 10;
	++y;
	if(y > x || reverse(y) >= y) return solve(x-1) + 1;
	return solve(reverse(y)) + (x-y) + 1;
}

int main(){
	int z;
	scanf("%d", &z);
	FWD(cas,1,z+1){
		LL n;
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", cas, solve(n));
	}
	return 0;
}
