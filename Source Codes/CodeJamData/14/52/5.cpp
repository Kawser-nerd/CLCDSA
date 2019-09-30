#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>

using namespace std;

int tt;
int h[110],g[110];
int f[110][1100];
int n,p,q;

void update(int &x,int y) {
	x=max(x,y);
}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d%d",&p,&q,&n);
		for (int i=0;i<n;++i)
			scanf("%d%d",&h[i],&g[i]);

		memset(f,255,sizeof(f));
		f[0][1]=0;
		for (int i=0;i<n;++i)
			for (int j=0;j<=10*i+1;++j)
				if (f[i][j]!=-1) {
					update(f[i+1][j+(h[i]-1)/q+1],f[i][j]);
					for (int k=1;k<=10;++k)
						for (int l=0;l<=10;++l) {
							int p1=(k-1)*p+l*q,p2=p1+p;
							if (h[i]>p1 && h[i]<=p2 && j+l-k>=0)
								update(f[i+1][j+l-k],f[i][j]+g[i]);
						}
				}
		int ans=0;
		for (int i=0;i<=10*n+1;++i)
			ans=max(ans,f[n][i]);
		printf("Case #%d: %d\n",ii,ans);
	}
}
