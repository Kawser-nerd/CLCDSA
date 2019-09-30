#include<stdio.h>
int main(){
	int N,i,j,a=0,b=0;
	scanf("%d",&N);
	int d[100];
	for(i=0;i<N;i++){
		scanf("%d",&d[i]);
	}
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(d[i]<d[j]){
				a=d[i];
				d[i]=d[j];
				d[j]=a;
			}
		}
	}
	for(i=0;i<N;i++){
		if(d[i]!=d[i+1]){
			b++;
		}
	}
	printf("%d",b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&d[i]);
   ^