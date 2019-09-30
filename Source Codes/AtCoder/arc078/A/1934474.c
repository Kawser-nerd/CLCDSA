#include<stdio.h>
#include<math.h>
int main(void)
{
	long long int a[200000],x,y=0,dim;
	int n,i,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	x=a[1];
	for(i=2;i<=n;i++)
	{
		y+=a[i];
	}
	dim=llabs(x-y);
	for(t=2;t<n;t++)
	{
		x+=a[t];
	    y-=a[t];
        if(llabs(x-y)<=dim)
        {
        	dim=llabs(x-y);
		}
	}
	printf("%lld",dim);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:6: warning: implicit declaration of function ‘llabs’ [-Wimplicit-function-declaration]
  dim=llabs(x-y);
      ^
./Main.c:17:6: warning: incompatible implicit declaration of built-in function ‘llabs’
./Main.c:17:6: note: include ‘<stdlib.h>’ or provide a declaration of ‘llabs’
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^