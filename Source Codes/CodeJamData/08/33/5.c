#include<stdio.h>
#include<math.h>
main()
{
long long int i,c[1000],j,k,l,t,m,n,A[1000],b[1000],X,Y,Z,ctr=0,flag=0;
scanf("%d",&t);
for(l=0;l<t;l++)
{
ctr=0;
scanf("%lld %lld %lld %lld %lld",&n,&m,&X,&Y,&Z);
for(i=0;i<m;i++)
scanf("%lld",&A[i]);
for (i = 0;i<n;i++)
{
  b[i]= A[i % m];
  A[i% m] = (X * A[i%m] + Y * (i + 1))% Z;
//printf("%d ",b[i]);
c[i]=1;
}
for(i=n-2;i>=0;i--)
for(j=i+1;j<n;j++)
if(b[j]>b[i])
c[i]=(c[j]+c[i])%1000000007;
for(i=0;i<n;i++)
ctr=(ctr+c[i])%1000000007;
printf("Case #%lld: %lld\n",l+1,ctr);
//long long int y=1000000007;
//printf("%lld",y);
}
}


