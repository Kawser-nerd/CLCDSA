#include<stdio.h>
int main(void){
	int N;
	scanf("%d",&N);
	int a;
	int p[N];
	int max=0;
	int sum=0;
	for(a=0;a<N;a++){
		scanf("%d",&p[a]);
		if(p[a]>max){
			max=p[a];
		}
		sum+=p[a];
	}
	printf("%d",sum-(max/2));
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&p[a]);
   ^