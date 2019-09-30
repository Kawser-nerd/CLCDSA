#include<stdio.h>
#include<math.h>
main()
{
int i,cnt,t,j,k,n,pl,a[5001],flag[5001];
scanf("%d",&t);
for(pl=0;pl<t;pl++)
{
scanf("%d",&k);
for(i=1;i<=k;i++)
flag[i]=0;
j=1;
for(i=1;i<=k;i++)
{
cnt=0;
while(cnt!=i)
{
if(flag[j]==0)
cnt++;
j++;
if(j>k)
j-=k;
}
if(j>1)
{a[j-1]=i;flag[j-1]=1;}
else
{a[k]=i;flag[k]=1;}
}
printf("Case #%d: ",pl+1);
scanf("%d",&n);
for(j=0;j<n;j++)
{
scanf("%d",&cnt);
printf("%d ",a[cnt]);
}
printf("\n");
}
}
