#include <bits/stdc++.h>

#define FI(i,a,b) for(int i=(a);i<=(b);i++)
#define FD(i,a,b) for(int i=(a);i>=(b);i--)

#define LL long long
#define Ldouble long double
#define PI 3.1415926535897932384626

#define PII pair<int,int>
#define PLL pair<LL,LL>
#define mp make_pair
#define fi first
#define se second

using namespace std;

map<LL, LL> M;

int t;
LL k, n;

void answer(LL x){
	printf("%lld %lld\n", x / 2, (x - 1) / 2);
	return;
}

void solve(){
	M.clear();
	M[n] = 1;
	while(1){
		map<LL, LL>::reverse_iterator rit = M.rbegin();
		LL u = (*rit).fi;
		LL v = (*rit).se;
		
		if(v >= k){
			answer(u);
			return;
		}
		else{
			k -= (*rit).se;
			if(!M.count(u / 2)) M[u / 2] = v;
			else M[u / 2] += v;
			if(!M.count((u - 1) / 2)) M[(u - 1) / 2] = v;
			else M[(u - 1) / 2] += v;
			M.erase(u);
		}
	}
}

int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C3.out", "w", stdout);
	scanf("%d", &t);
	FI(tt, 1, t){
		scanf("%lld %lld", &n, &k);
		printf("Case #%d: ", tt);
		solve();
	}
	return 0;
}

