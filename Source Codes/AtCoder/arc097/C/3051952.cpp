#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

int n,p[2][2002],cache[2002][2002];
int ps[2][2002][4002];

int DP(int a,int b) {
	int &ret=cache[a][b];
	if(ret!=-1) return ret;

	if(a==n+1 && b==n+1) return ret=0;
	ret = 1e9;

	if(a<=n) ret = min(ret, DP(a+1,b) + ps[0][n][p[0][a]]-ps[0][a][p[0][a]] + ps[1][n][p[0][a]]-ps[1][b-1][p[0][a]]);
	if(b<=n) ret = min(ret, DP(a,b+1) + ps[1][n][p[1][b]]-ps[1][b][p[1][b]] + ps[0][n][p[1][b]]-ps[0][a-1][p[1][b]]);
	
	return ret;
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++) {
		char ch;
		int a,b;
		scanf(" %c %d",&ch,&b);
		if(ch=='W') a=0;
		else a=1;

		p[a][b] = i;
		ps[a][b][i] = 1;
	}
	for(int i=0;i<2;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n*2;k++)
		ps[i][j][k] += ps[i][j-1][k] + ps[i][j][k-1] - ps[i][j-1][k-1];

	memset(cache,-1,sizeof(cache));
	printf("%d\n",DP(1,1));

	return 0;
}