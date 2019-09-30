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

int t, s[22], dig;
LL n;

vector<LL> num;

void gen(LL val, int dig, int pla){
	if(val) num.push_back(val);
	if(pla < 18){
		FI(i, dig, 9) gen(val * 10 + i, i, pla + 1);
	}
	return;
}

int main(){
	gen(0, 1, 0);
	sort(num.begin(), num.end());
	
	freopen("B-large.in", "r", stdin);
	freopen("B2.out", "w", stdout);
	
	scanf("%d", &t);
	FI(tt, 1, t){
		scanf("%lld", &n);
		printf("Case #%d: ", tt);
		int l = -1, r = num.size();
		while(r - l > 1){
			int m = (l + r) >> 1;
			if(num[m] <= n) l = m;
			else r = m;
		}
		printf("%lld\n", num[l]);
	}
	return 0;
}

