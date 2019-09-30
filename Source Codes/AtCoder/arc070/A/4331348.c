#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int i;
	int sum=0;
	for(i=1;i<n;i++){
		sum+=i;
		if(sum>=n){
			break;
		}
	}
	printf("%d",i);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^