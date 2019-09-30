#include <stdio.h>
int main(void)
{
    int w,h,n;
    long long int ans;
    scanf("%d%d%d", &w,&h,&n);
    int x[n], y[n], a[n];
    for(int i=0; i<n; i++) scanf("%d%d%d", &x[i],&y[i],&a[i]);
    
    int p[2],q[2];
    p[0]=0;
    p[1]=0;
    q[0]=w;
    q[1]=h;
    for(int i=0; i<n; i++)
    {
        if(a[i]==1)
        {
            if(p[0]<x[i]) p[0]=x[i];
        }
        else if(a[i]==2)
        {
            if(q[0]>x[i]) q[0]=x[i];
        }
        else if(a[i]==3)
        {
            if(p[1]<y[i]) p[1]=y[i];
        }
        else
        {
            if(q[1]>y[i]) q[1]=y[i];
        }
    }
    ans=(q[0]-p[0])*(q[1]-p[1]);
    if(ans>0 && q[0]-p[0]>0 && q[1]-p[1]);
    else ans=0;

    printf("%lld", ans);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &w,&h,&n);
     ^
./Main.c:8:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0; i<n; i++) scanf("%d%d%d", &x[i],&y[i],&a[i]);
                            ^