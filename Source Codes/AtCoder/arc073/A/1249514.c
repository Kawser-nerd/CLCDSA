#include<stdio.h>

int main(void){
	int n,t,i,f,res = 0,d[262144];
	scanf("%d%d",&n,&t);
	for(i = 1;i <= n;i++){
		scanf("%d",&d[i]);
		if(i == 1){f = d[i];}
		else{
			if(d[i] - d[i-1] > t){res+=(d[i-1]+t-f);f=d[i];}
		}
	}
	res+=(d[n]+t-f);
	printf("%d\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&t);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&d[i]);
   ^