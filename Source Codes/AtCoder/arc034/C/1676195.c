#include<stdio.h>
int main(){
	int a,b,i,j,M=1e9+7,c[100010]={};
	long long s=1;
	scanf("%d %d",&a,&b);
	for(i=b+1;i<=a;i++){
		b=i;//printf("%d\n",i);fflush(stdout);
		for(j=2;j*j<=i;j++){
			for(;b%j==0;b/=j)c[j]++;
		}
		if(1LL*b*b>1e6)s=(s*2)%M;//printf("a\n");fflush(stdout);
		else c[b]++;
	}//printf("b\n");fflush(stdout);
	for(i=2;i*i<=M;i++)s=(s*(c[i]+1))%M;
	printf("%lld\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^