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

int t, len, k;
char s[1005];

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A2.out", "w", stdout);
	scanf("%d", &t);
	FI(tt, 1, t){
		scanf(" %s %d", s, &k);
		len = strlen(s);
		
		printf("Case #%d: ", tt);
		
		int need = 0;
		FI(i, 0, len - k){
			if(s[i] == '-'){
				need++;
				FI(j, i, i + k - 1){
					if(s[j] == '-') s[j] = '+';
					else s[j] = '-';
				}
			}
		}
		FI(i, 0, len - 1) if(s[i] == '-'){
			printf("IMPOSSIBLE\n");
			goto gg;
		}
		printf("%d\n", need);
		gg:;
	}
	return 0;
}

