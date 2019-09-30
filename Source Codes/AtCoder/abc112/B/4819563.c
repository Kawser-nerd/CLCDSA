#include<stdio.h>
int main(void){
	int N,T;
	scanf("%d%d",&N,&T);
	int a;
	int c,t;
	int min=1001;
	for(a=0;a<N;a++){
		scanf("%d%d",&c,&t);
		if(t<=T){
			if(c<min){
				min=c;
			}
		}
	}
	if(min==1001){
		printf("TLE");
	}else{
		printf("%d",min);
	}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&T);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&c,&t);
   ^