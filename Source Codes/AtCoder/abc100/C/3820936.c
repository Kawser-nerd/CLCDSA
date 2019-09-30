#include<stdio.h>

int main(){
	int N,ans=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		while(a%2==0){
			ans++;
			a/=2;
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^