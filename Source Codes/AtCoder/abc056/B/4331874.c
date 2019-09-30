#include<stdio.h>

int main()
{
	int t,a,b,w;
    scanf("%d %d %d",&w,&a,&b);
	if(a>b)
	{
	t=a;
	a=b;
	b=t;
	}


    if(a+w>=b)
	printf("0");
	else
	printf("%d",b-(a+w));
		
//	int d,a,b,w;

//	d=abs(a-b);
//	printf("%d",d);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&w,&a,&b);
     ^