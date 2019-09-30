#include<stdio.h>

int main(void){
	long long n,a[131072],r,i,c,d,s;
	scanf("%lld",&n);
	for(i = 1;i <= n;i++){scanf("%lld",&a[i]);}
	s=0;c=0;
	for(i = 1;i <= n;i++){
		s+=a[i];
		if(i%2 == 1 && s <= 0){c+=(1-s);s=1;}
		if(i%2 == 0 && s >= 0){c+=(s-(-1));s=-1;}
	}
	s=0;d=0;
	for(i = 1;i <= n;i++){
		s+=a[i];
		if(i%2 == 1 && s >= 0){d+=(s-(-1));s=-1;}
		if(i%2 == 0 && s <= 0){d+=(1-s);s=1;}
	}
	if(c<d){printf("%lld\n",c);}else{printf("%lld\n",d);}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:6:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 1;i <= n;i++){scanf("%lld",&a[i]);}
                        ^