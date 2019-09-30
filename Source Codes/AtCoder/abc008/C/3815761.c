#include<stdio.h>
short N, num, a, i, j;
double ans;
int C[100];
int main(){
	scanf("%hd", &N);
	for(i=0; i<N; ++i){
		scanf("%d", C+i);
	}
	for(i=0; i<N; ++i){
		num=-1;
		for(j=0; j<N; ++j){
			if(C[i]%C[j]==0){++num;}
		}
		if(num&1){
			ans+=0.5;
		}else{
			ans+=(num+2.0)/(num*2+2.0);
		}
	}
	printf("%lf\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd", &N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", C+i);
   ^