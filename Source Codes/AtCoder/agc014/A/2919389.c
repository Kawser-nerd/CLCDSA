#include<stdio.h>
int main(){
	int a,b,c,num=0,a1,b1,c1,f=1;
	scanf("%d%d%d",&a,&b,&c);
	while(a%2==0 && b%2==0 && c%2==0){
		a1=a/2;
		b1=b/2;
		c1=c/2;
		a=b1+c1;
		b=a1+c1;
		c=a1+b1;
		num++;
		if(a==b && b==c){
			f=0;
			printf("-1\n");
			break;
		}
	}
	if(f==1)printf("%d\n",num);
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^