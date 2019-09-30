#include<stdio.h>
#include<math.h>
sort(long long int a[], long long int n)
{
int i,j,temp;
for(i=0;i<n;i++)
for(j=i;j<n;j++)
if(a[i]<a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}

main()
{
long long int cyt,p,i,j,k,a[1000],l,t,m,n,ctr=0,flag=0;
scanf("%lld",&t);
for(m=0;m<t;m++)
{
for(j=0;j<1000;j++)
a[j]=0;
ctr=0;
scanf("%lld %lld %lld",&p,&n,&l);
for(j=0;j<l;j++)
{scanf("%lld",&a[j]);}
cyt=1;
sort(a,l);
//for(j=0;j<l;j++)
//printf("%ld ",a[j]);
for(j=0;j<l;)
{
for(i=0;i<n;i++)
ctr+=a[j++]*cyt;
//printf("cnt %ld ",ctr);
cyt++;
}
printf("Case #%lld: ",m+1);
if(cyt>p+1)
printf("Impossible\n");
else
printf("%lld\n",ctr);
}
}


