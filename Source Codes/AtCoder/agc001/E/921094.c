#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define AB 2000
#define AB2 4001
#define N 200005

typedef struct set {
	int a;
	int b;
} set;

int main(){
	int i,j;
	long long int ii,jj,rii,rjj;
	int n;
	int a,b;
	long long int **dp;
	long long int **root;
	long long int res = 0;
	set s[N];
	dp = calloc(sizeof(long long int*),AB2);
	for(i = 0;i < AB2;i++){
		dp[i] = calloc(sizeof(long long int),AB2);
	}
	root = calloc(sizeof(long long int*),AB2);
	for(i = 0;i < AB2;i++){
		root[i] = calloc(sizeof(long long int),AB2);
	}
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d %d",&a,&b);
		s[i].a = a;
		s[i].b = b;
		root[AB - a][AB - b]++;
	}
	dp[0][0] = 1;
	for(i = 0;i < AB2;i++){
		for(j = 0;j < AB2;j++){
			ii = (i == 0 ? 0 : dp[i - 1][j]);
			jj = (j == 0 ? 0 : dp[i][j - 1]);
			rii = (i == 0 ? 0 : root[i - 1][j]);
			rjj = (j == 0 ? 0 : root[i][j - 1]);
			dp[i][j] += (ii + jj);
			dp[i][j] %= MOD;
			root[i][j] += (rii + rjj);
			root[i][j] %= MOD;
		}
	}
	for(i = 0;i < n;i++){
		res += root[AB + s[i].a][AB + s[i].b];
		res %= MOD;
		res += MOD - dp[s[i].a*2][s[i].b*2];
		res %= MOD;
	}
	printf("%lld\n", res % 2 == 0 ? res / 2 : (res + MOD) / 2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^