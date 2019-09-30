#include <stdio.h>
int main(void){
	int n,i,a,x[21];
	long long int v=0,xm;
	scanf("%d%d",&n,&xm);
	for(i=0;i<n;i++){
		x[i]=xm%2;
		scanf("%d",&a);
		if(x[i]==1) v+=a;
		xm/=2;
	}
	printf("%lld\n",v);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
  scanf("%d%d",&n,&xm);
        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&xm);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^