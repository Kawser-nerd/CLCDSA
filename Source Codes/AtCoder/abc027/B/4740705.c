#include <stdio.h>
#include <stdlib.h>
int main(void){
	int N,i;
	scanf("%d",&N);
	int a[N],sum=0;
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%N!=0)printf("-1\n");
	else{
		int people = sum/N;
		int c = 0;
		int sum=0;
		for(i=0;i<N;i++){
			sum += a[i];
			if(sum!=people*(i+1)){
				c++;
			}
		}
		printf("%d\n",c);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^