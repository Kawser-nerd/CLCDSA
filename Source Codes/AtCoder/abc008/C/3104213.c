#include<stdio.h>

int main(){
	int N,i,j,c;
	float sum=0;
	scanf("%d",&N);
	int C[N];
	for(i=0;i<N;i++) scanf("%d",&C[i]);
	
	for(i=0;i<N;i++){
		c=0;
		for(j=0;j<N;j++){
			if(C[i]%C[j]==0) c++;
		}
		if(c%2==0) sum+=0.5;
		else sum+=(float)(c+1)/(2*c);
	}
	
	printf("%f\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:8:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++) scanf("%d",&C[i]);
                   ^