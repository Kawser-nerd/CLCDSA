#include<stdio.h>
#include<stdlib.h>
int asc(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	unsigned long long int n;
	scanf("%lld",&n);
	unsigned long long int i;
	int a[100005],b[100005],c[100005];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	qsort(a,n,sizeof(int),asc);
	qsort(b,n,sizeof(int),asc);
	qsort(c,n,sizeof(int),asc);
	a[n]=2000000000;
	c[n]=2000000000;
	unsigned long long int j,k;
	unsigned long long int ans=0;
	i=j=k=0;
	while(a[i]>=b[j] && j<n)
		j++;
	for(;j<n;j++)
	{
		while(a[i]<b[j])
			i++;
		while(b[j]>=c[k])
			k++;
		ans+=i*(n-k);
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b[i]);
   ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&c[i]);
   ^