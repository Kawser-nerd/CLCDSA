#include <stdio.h>

int f[110][110][110];
int x[4];

int max(int a,int b) {return a>b?a:b;
}

int main(){
	for (int i=0; i<=100; ++i)
	for (int j=0; j<=100-i; ++j)
	for (int k=0; k<=100-i-j; ++k) {
		if (f[i][j][k] >= f[i+4][j][k]) f[i+4][j][k] = f[i][j][k] + 1;
		if (f[i][j][k] >= f[i][j+2][k]) f[i][j+2][k] = f[i][j][k] + 1;
		if (f[i][j][k] >= f[i+4][j][k]) f[i+4][j][k] = f[i][j][k] + 1;
		if (f[i][j][k] >= f[i+1][j][k+1]) f[i+1][j][k+1] = f[i][j][k] + 1;
		if (f[i][j][k] >= f[i+4][j][k]) f[i+4][j][k] = f[i][j][k] + 1;
		if (f[i][j][k] >= f[i+2][j+1][k]) f[i+2][j+1][k] = f[i][j][k] + 1;
		if (f[i][j][k] >= f[i][j+1][k+2]) f[i][j+1][k+2] = f[i][j][k] + 1;
	}
	
	int t; scanf("%d",&t);
	for (int i=1; i<=t; ++i) {
		int n,d; scanf("%d%d",&n,&d);
		x[0]=x[1]=x[2]=x[3]=0;
		for(int j=1; j<=n; ++j) {
			int p; scanf("%d",&p);
			x[p%d]++;
		}
		printf("Case #%d: ",i);
		int ans=0;
		if (d==2) ans = x[0]+(x[1]+1)/2;
		else if (d==3) {
			ans = x[0];
			if (x[1]>=x[2]) ans += x[2] + (x[1]-x[2]+2)/3;
			else ans += x[1] + (x[2]-x[1]+2)/3;
		}
		else {
			if (x[1] > 0) ans = 1 + f[x[1]-1][x[2]][x[3]];
			if (x[2] > 0) ans = max(ans, 1 + f[x[1]-1][x[2]][x[3]]);
			if (x[3] > 0) ans = 1 + max(ans, f[x[1]][x[2]][x[3]-1]);
			ans += x[0];
		}
		printf("%d\n",ans);
	}
}
