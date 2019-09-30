#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int tt;
int n,s;
int a[1010][3];
int v[1010][3];
int dist[1010];
bool used[1010];

inline int sqr(int x) {
	return x*x;
}

int dis(int p,int q) {
	return sqr(a[p][0]-a[q][0])+sqr(a[p][1]-a[q][1])+sqr(a[p][2]-a[q][2]);
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d",&n,&s);
		for (int i=0;i<n;++i)
			scanf("%d%d%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&v[i][0],&v[i][1],&v[i][2]);

		for (int i=0;i<n;++i)
			dist[i]=100000000,used[i]=false;
		dist[0]=0;

		for (int i=0;i<n;++i) {
			int x=-1;
			for (int j=0;j<n;++j)
				if (!used[j])
					if (x==-1 || dist[j]<dist[x]) x=j;
			used[x]=true;
			for (int j=0;j<n;++j)
				dist[j]=min(dist[j],max(dist[x],dis(x,j)));
		}

		printf("Case #%d: %.10f\n",ii,sqrt(dist[1]));

	}
}