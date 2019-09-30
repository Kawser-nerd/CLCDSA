#include <stdio.h>
#include <stdlib.h>

int e[101]={0};
int N;
//
int num(int n){
	int c = 0;
	for(int i=2;i<=N;i++){
		if(e[i]>=n-1)c++;
	}
	return c;
}

int main(void){
	int i,j,ans;
	scanf("%d",&N);
	for(i=2;i<=N;i++){
		int kazu = i;
		for(j=2;j<=i;j++){
			while(kazu%j==0){
				e[j]++;
				kazu /= j;
			}
		}
	}
	ans = num(75) + num(25)*(num(3)-1) + num(15)*(num(5)-1) + num(5)*(num(5)-1)*(num(3)-2)/2;
	printf("%d",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^