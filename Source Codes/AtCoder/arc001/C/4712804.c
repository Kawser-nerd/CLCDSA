#include<stdio.h>
#include<stdlib.h>

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	a=abs(a-b);
	int ans=0;
	ans+=a/10;
	if(a%10<5){
		if(a%5==0);
		else if(1<=a%5&&a%5<=3)ans+=a%5;
		else ans+=2;
	}else if(a%10<=7)ans+=(1+a%5);
	else if(a%10==8)ans+=3;
	else if(a%10==9)ans+=2;
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^