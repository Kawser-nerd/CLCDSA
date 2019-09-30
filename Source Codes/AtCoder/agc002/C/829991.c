#include <stdio.h>

int main(void){
	long long int n,l;
	scanf("%lld%lld",&n,&l);
	int i;
	int a[100009];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int lastcut=-1;
	for(i=0;i<n-1;i++){
		if(a[i]+a[i+1]>=l){
			lastcut=i+1;
			break;
		}
	}
	if(lastcut==-1){
		printf("Impossible\n");
	}else{
		printf("Possible\n");
		for(i=1;i<lastcut;i++){
			printf("%d\n",i);
		}
		for(i=n-1;i>=lastcut;i--){
			printf("%d\n",i);
		}
	}

	return 0;

} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&l);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^