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

int solve(int n, int m, int k){
	int res = n*m*4;
	vector<int> S;
	FWD(i,0,n*m-k) S.push_back(0);
	FWD(i,0,k) S.push_back(1);
	do{
		int cur = 0;
		FWD(i,0,n) FWD(j,0,m-1) if(S[i*m+j] && S[i*m+j+1]) ++cur;
		FWD(i,0,n-1) FWD(j,0,m) if(S[i*m+j] && S[i*m+m+j]) ++cur;
		res = min(res, cur);
	}while(next_permutation(S.begin(), S.end()));
	return res;
}

int fast(int n, int m, int k){
	if(n > m) swap(n, m);
	if(n == 1){
		if(m&1){
			if(k <= (m+1)/2) return 0;
			return (k - (m+1)/2) * 2;
		}else{
			if(k <= m/2) return 0;
			if(k == m/2+1) return 1;
			return (k - m/2) * 2 - 1;
		}
	}
	if(k <= (n*m+1) / 2) return 0;
	if(k >= n*m - ((n-2)*(m-2)+1)/2) return (n*m*4 - 2*n - 2*m) / 2 - (n*m-k) * 4;
	k -= (n*m+1) / 2;
	if((n&1) && (m&1)){
		if(k == 1) return 3;
		if(k == 2) return 6;
		return 3*k - 1;
	}else{
		if(k == 1) return 2;
		if(k == 2) return 4;
		return 3*k - 2;
	}
}

int main(){
	int z;
	scanf("%d", &z);
	FWD(cas,1,z+1){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		printf("Case #%d: %d\n", cas, fast(n, m, k));
	}
	return 0;
}
