#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
double f[1005][1005],dis[1005],a[1005][3];
bool b[1005];
int main()
{
	int i,j,k,n;
	double xi,xs,ys,xt,yt;
	scanf("%lf%lf%lf%lf",&xs,&ys,&xt,&yt);
	scanf("%d",&n);
	a[0][0]=xs;a[0][1]=ys;a[0][2]=0;
	a[n+1][0]=xt;a[n+1][1]=yt;a[n+1][2]=0;
	for(i=1;i<=n;i++)
		scanf("%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2]);
	n++;
	for(i=0;i<=n;i++)
		for(j=i+1;j<=n;j++)
			f[i][j]=f[j][i]=max(0.0,sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]))-(a[i][2]+a[j][2]));
	for(i=0;i<=1003;i++) dis[i]=1e18;
	dis[0]=0; 
	for(i=0;i<n;i++){ 
		xi=1e18;
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
	printf("%.9lf",dis[n]);
}