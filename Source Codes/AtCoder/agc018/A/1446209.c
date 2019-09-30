#include<stdio.h>
#include<stdlib.h>

int retGCD(int a,int b);

int main(void){
	int n,k,i,max=0,in;
	int gcd;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&in);
		if(max<in) max=in;
		if(i==0) gcd=in;
		else gcd=retGCD(gcd,in);
	}
	if(max<k || k%gcd>0) puts("IMPOSSIBLE");
	else puts("POSSIBLE");
	return 0;
}

int retGCD(int a,int b){
	if(a<b){
		int tmp=a;
		a=b;
		b=tmp;
	}
	if(b==0) return a;
	else return retGCD(b,a%b);
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&k);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&in);
   ^