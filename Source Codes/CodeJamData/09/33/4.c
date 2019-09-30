#include<stdio.h>
#include<string.h>
 
#define MAXN 1024
#define inf 1000000000
 
int d[MAXN][MAXN],p[MAXN][MAXN];
 
int main()
{
        int a[MAXN];
        int n,m,i,j,k;
	int N,cs=0;
 
        for(scanf("%d",&N);N--;)
        {
		scanf("%d %d",&n,&m);
                for(a[0]=0,i=1;i<=m;i++) scanf("%d",&a[i]);
                if (m==1) {printf("Case #%d: %d\n",++cs,n-1);continue;}
                a[i]=n+1,m++;
                memset(d,0,sizeof(d));
                for(i=0;i<=m-2;i++) d[i][i+2]=a[i+2]-a[i]-2,p[i][i+2]=i+1;
                for(i=3;i<=m;i++)
                        for(j=0;j<=m-i;d[j][j+i]+=a[j+i]-a[j]-2,j++)
                                for(d[j][j+i]=inf,k=p[j][j+i-1];k<=p[j+1][j+i];k++)
                                        if (d[j][k]+d[k][j+i]<d[j][j+i]) d[j][j+i]=d[j][k]+d[k][j+i],p[j][j+i]=k;
                printf("Case #%d: %d\n",++cs,d[0][m]);
        }
        return 0;
}
