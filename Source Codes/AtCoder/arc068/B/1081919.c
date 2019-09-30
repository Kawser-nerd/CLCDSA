#include<stdio.h>

int main(void){
	int c[131072]={0},i,r=0,n,x,m;
	scanf("%d",&n);
	for(i = 1;i <= n;i++){scanf("%d",&m);c[m]++;}
	m = 0;
	for(i = 1;i <= 114514;i++){
		if(c[i] == 0){continue;}
		if(c[i] % 2 == 1){r+=((c[i]-1)/2);}
		else{r+=((c[i]-1)/2);m++;}
	}
	if(m % 2 == 1){r+=((m+1)/2);}
	else{r+=(m/2);}
	printf("%d\n",n-2*r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 1;i <= n;i++){scanf("%d",&m);c[m]++;}
                        ^