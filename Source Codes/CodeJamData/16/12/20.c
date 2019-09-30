#include<stdio.h>
int main()
{
int t,i,n;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
int hash[3000]={0};
scanf("%d",&n);
int temp=n*(2*n-1),j;
while(temp>0)
{
int x;
scanf("%d",&x);
hash[x]++;
temp--;
}
printf("Case #%d:",i);
for(j=1;j<=2500;j++)
{
if(hash[j])
{
if(hash[j]%2==1)
printf(" %d",j);
}
}
printf("\n");
}
return 0;
}
