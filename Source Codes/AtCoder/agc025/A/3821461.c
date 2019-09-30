#include <stdio.h>
int n;
int ten[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int aaa[4]={3,5,7};
int result=0;


int main(){
	int b,as,bs;
	int result=9999;
	scanf("%d",&n);
	
	for(int a=1;a<n;a++)
	{
		b=n-a;
		as=a%10+(a/10)%10+(a/100)%10+(a/1000)%10+(a/10000)%10+(a/100000)%10;
		bs=b%10+(b/10)%10+(b/100)%10+(b/1000)%10+(b/10000)%10+(b/100000)%10;
		if(as+bs<result)
		{
			result=as+bs;
		}
	}
	printf("%d",result);
	} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^