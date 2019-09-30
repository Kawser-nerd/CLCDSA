#include <stdio.h>

int main(void) {
	int a[3]={0,0,1};
	long int n,tmp1=0,tmp2=0,tmp3=1,an;
	scanf("%ld",&n);
	if (n>3){
		for(int i=4;i<=n;i++){
			an=(tmp1+tmp2+tmp3)%10007;
			tmp1=tmp2;
			tmp2=tmp3;
			tmp3=an;
		}
	}
	if(n<4)printf("%d\n",a[n-1]);
	else printf("%ld\n",an);
	return 0;
		} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^