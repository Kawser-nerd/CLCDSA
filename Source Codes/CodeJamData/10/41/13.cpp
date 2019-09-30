#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N=120;
char a[N][N];
bool u[N][N];
int st[N],n;

int check(int x,int y,int z){
	if (x<=0||x>=2*n) return true;
	if (y<=0||y>=2*n) return true;
	if (u[x][y]==false) return true;
	return z==a[x][y];
}
int main(){
	int tt,cas,i,j;
	scanf("%d",&tt);
	for (cas=1;cas<=tt;cas++){
		scanf("%d",&n);
		memset(u,0,sizeof(u));
		for (i=1;i<=n;i++)
			st[i]=st[2*n-i]=n-i+1;
		for (i=1;i<=n;i++)
			for (j=1;j<=i;j++){
				scanf("%d",&a[i][st[i]+j*2-2]);
				u[i][st[i]+j*2-2]=true;
			}
		for (i=n+1;i<=2*n-1;i++)
			for (j=1;j<=2*n-i;j++){
				scanf("%d",&a[i][st[i]+j*2-2]);
				u[i][st[i]+j*2-2]=true;
			}
		int ans=2*n+1,x,y,x1,y1;
		for (x=1;x<=2*n-1;x++)
			for (y=1;y<=2*n-1;y++){
				// 划定中心
				int f=true;
				for (i=1;f&&i<=n;i++)
					for (j=1;f&&j<=i;j++){
						x1=2*x-i,y1=(st[i]+j*2-2);
						f=f&&check(x1,y1,a[i][st[i]+j*2-2]);
						x1=i,y1=2*y-(st[i]+j*2-2);
						f=f&&check(x1,y1,a[i][st[i]+j*2-2]);
					}
				for (i=n+1;f&&i<=2*n-1;i++)
					for (j=1;f&&j<=2*n-i;j++){
						x1=2*x-i,y1=(st[i]+j*2-2);
						f=f&&check(x1,y1,a[i][st[i]+j*2-2]);
						x1=i,y1=2*y-(st[i]+j*2-2);
						f=f&&check(x1,y1,a[i][st[i]+j*2-2]);
					}
				if (f) ans=min(ans,abs(x-n)+abs(y-n));
			}
			/*
		for (i=1;i<=2*n-1;i++){
			for (j=1;j<=2*n-1;j++)
				printf("%2d",a[i][j]);
			puts("");
		}*/
		ans+=n;
		ans=ans*ans-n*n;
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
