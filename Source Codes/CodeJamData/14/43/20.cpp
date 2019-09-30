#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf 1050000000

using namespace std;

struct node {
	int x,y;

	node() {x=0,y=0;}
	node(int xx,int yy) {x=xx,y=yy;}
};

int tt;
int xx0[1100],yy0[1100],xx1[1100],yy1[1100];
int w,h,n;
int g[1100][1100];
bool used[1100];
int dist[1100];

int getdist(int i,int j) {
	int px=inf,py=inf;
	if (yy0[i]>yy1[j] || yy1[i]<yy0[j]) py=min(abs(yy0[i]-yy1[j]),abs(yy1[i]-yy0[j]))-1;
	else py=0;
	if (xx0[i]>xx1[j] || xx1[i]<xx0[j]) px=min(abs(xx0[i]-xx1[j]),abs(xx1[i]-xx0[j]))-1;
	else px=0;
	return max(px,py);
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);

	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d%d",&w,&h,&n);
		for (int i=0;i<n;++i)
			scanf("%d%d%d%d",&xx0[i],&yy0[i],&xx1[i],&yy1[i]);

		xx0[n]=-1; yy0[n]=0; xx1[n]=-1; yy1[n]=h-1;
		n++;
		xx0[n]=w; yy0[n]=0; xx1[n]=w; yy1[n]=h-1;
		n++;

		for (int i=0;i<n;++i)
			for (int j=i+1;j<n;++j)
				g[i][j]=g[j][i]=getdist(i,j);

		for (int i=0;i<n;++i)
			dist[i]=inf,used[i]=false;
		dist[n-2]=0;
		for (int i=0;i<n;++i) {
			int k=-1;
			for (int j=0;j<n;++j)
				if (!used[j] && (k==-1 || dist[j]<dist[k]))
					k=j;
			used[k]=true;
			if (dist[k]==inf) break;
			for (int j=0;j<n;++j)
				dist[j]=min(dist[j],dist[k]+g[k][j]);
		}
		printf("Case #%d: %d\n",ii,dist[n-1]);
	}
}
