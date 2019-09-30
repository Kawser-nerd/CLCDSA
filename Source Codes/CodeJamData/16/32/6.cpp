#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,b[60][60];
long long m;
int main(){
	freopen("Bl.in","r",stdin);
	freopen("Bl.out","w",stdout);
	int t; scanf("%d",&t);
	for (int k=1;k<=t;k++){
		scanf("%d%lld",&n,&m);
		printf("Case #%d: ",k);
		if ((1ll<<n-2)<m){
			printf("IMPOSSIBLE\n"); continue;
		}
		memset(b,0x00,sizeof b);
		for (int i=2;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				b[i][j]=1;
		if ((1ll<<n-2)==m){
			for (int i=2;i<=n;i++) b[1][i]=1;
		} else {
			for (int i=0;i<=n-3;i++)
				if (m&(1ll<<i)) b[1][n-1-i]=1;
		}
		printf("POSSIBLE\n");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)
				putchar('0'+b[i][j]);
			putchar('\n');
		}
	}
	return 0;
}

	
	
