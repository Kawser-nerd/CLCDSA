#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
double f[1005][1005],dis[1005];
int a[1005][3];
bool b[1005];
int main()
{
	int xs,ys,xt,yt,i,j,k,n;
	double xi;
	scanf("%d%d%d%d",&xs,&ys,&xt,&yt);
	scanf("%d",&n);
	a[0][0]=xs;a[0][1]=ys;a[0][2]=0;
	a[n+1][0]=xt;a[n+1][1]=yt;a[n+1][2]=0;
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	n++;
	for(i=0;i<=n;i++)
		for(j=i+1;j<=n;j++){
			f[i][j]=f[j][i]=1.0*sqrt(1.0*(a[i][0]-a[j][0])*(a[i][0]-a[j][0])+1.0*(a[i][1]-a[j][1])*(a[i][1]-a[j][1]))-1.0*(a[i][2]+a[j][2]);
			if(f[i][j]<0)
				f[j][i]=f[i][j]=0;
		}
	for(i=1;i<=n;i++) 
		dis[i]=f[0][i];
	b[0]=1; 
	dis[0]=0; 
	for(i=0;i<=n-1;i++){ 
		xi=2000000000; 
		k=0; 
		for(j=0;j<=n;j++){
            if(b[j]==0&&dis[j]<xi){ 
				xi=dis[j]; 
				k=j; 
			} 
        }
		b[k]=1; 
		for(j=0;j<=n;j++)
			dis[j]=min(dis[j],dis[k]+f[k][j]);
	}
	printf("%.10f",dis[n]);
}