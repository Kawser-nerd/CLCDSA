#include<stdio.h>
int main()
{
	int a,b,c;
	int A,B,C;
	scanf("%d%d%d",&a,&b,&c);
	int sum=0;
	int f=0;
	int t=1000;
	while(t--){
		if(a%2!=0||b%2!=0||c%2!=0){
			f=1;
			break;
		}
		A=a;
		a=(b+c)/2;
		B=b;
		b=(A+c)/2;
		C=c;
		c=(A+B)/2;
		sum++;	
	}
	if(f==1) printf("%d\n",sum);
	else printf("-1\n");
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^