#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<complex>

using namespace std;

const int inf = 2147483647;
const double eps = 1e-9;
const double pi = acos(-1.0);

const int maxn = 1000;
const int mod = 1000003;

int n, m;
int cnt[26];
long long dp[27][205];
char s[1000000];
long long C[1000000][205];

long long calc(int holes, int hole_c, int sum, int other, int total)
{
	if(sum-holes+1<0) return 0;
	if(total==0)
	{
		if(hole_c+other != 0) return 0;
		else return 1;
	}
	if(hole_c+other-1 < 0) return 0;
	long long res = C[holes][hole_c] * C[sum-holes+1][other] % mod;
	res = res * C[total-1][hole_c+other-1] % mod;
	return res;
}

void init()
{
	C[0][0] = 1;
	for(int i=1; i<1000000; i++)
	{
		C[i][0] = 1;
		for(int j=1; j<=i && j<205; j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int ntest;
	init();
	scanf("%d",&ntest);
	for(int test=1; test<=ntest; test++)
	{
		fprintf(stderr,"%d\n",test);
		memset(cnt, 0, sizeof(cnt));
		scanf("%s", &s); n = strlen(s);
		m = 0;
		for(int i=0; i<n; i++)
		{
			if(i==0 || s[i]!=s[i-1]) m++;
			cnt[s[i]-'a']++;
		}

		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		int acc = 0;
		for(int i=0; i<26; i++)
		{
			for(int j=0; j<=m; j++)
			{
				if(dp[i][j]==0) continue;
				for(int k=0; j+k<=m; k++)
					for(int p=0; p<=k; p++)
						dp[i+1][j+k+p] = (dp[i+1][j+k+p] + dp[i][j] * calc(j+1, k-p, acc, p, cnt[i])) % mod;
			}
			acc += cnt[i];
		}

		printf("Case #%d: %I64d\n", test, dp[26][m]);
	}
	return 0;
}
