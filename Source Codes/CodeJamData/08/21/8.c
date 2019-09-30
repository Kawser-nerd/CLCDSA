#include<stdio.h>
#include<math.h>
main()
{
long long int i,t,j,k,l,cnt=0,p,A,B,C,D,x,y,m,n,a[100][2];
scanf("%lld",&t);
for(i=0;i<t;i++)
{
cnt=0;
scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&n,&A,&B,&C,&D,&x,&y,&m);
a[0][0]=x;
a[0][1]=y;
for(j=1;j<n;j++)
{x=(A*x+B)%m;
y=(C*y+D)%m;
a[j][0]=x;
a[j][1]=y;
}
for(k=0;k<n;k++)
for(l=k+1;l<n;l++)
for(p=l+1;p<n;p++)
if(((a[k][0]+a[l][0]+a[p][0])%3==0)&&((a[k][1]+a[l][1]+a[p][1])%3==0))
cnt++;
printf("Case #%lld: %lld\n",i+1,cnt);
}
}
