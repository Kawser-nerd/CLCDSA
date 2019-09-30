#include<stdio.h>
int main(){
	double max=0,p;
	int n,a,b,c,d,e;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		p=a+b+c+d+e*110.0/900;
		if(max<p)max=p;
	}
	printf("%f\n",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
   ^