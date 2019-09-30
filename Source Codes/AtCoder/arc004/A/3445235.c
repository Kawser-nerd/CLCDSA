#include<stdio.h>>
#include<math.h>
int n,x[101],y[101],i,j;
double ans;
inline double dis(int i,int j)
{
    int xx=x[i]-x[j],yy=y[i]-y[j];
    return sqrt(xx*xx+yy*yy);
}
inline double max(double a,double b)
{
    return a>b?a:b;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    ans=max(ans,dis(i,j));
    printf("%.10f",ans);
    return 0;
} ./Main.c:1:18: warning: extra tokens at end of #include directive
 #include<stdio.h>>
                  ^
./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x[i],&y[i]);
     ^