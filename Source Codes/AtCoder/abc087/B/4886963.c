#include<stdio.h>

int num[40000];

int main(void) {
	int i,j,k,A,B,C,X;
	scanf("%d%d%d%d",&A,&B,&C,&X);
	for(i=0;i<=A;i++) {
		for(j=0;j<=B;j++) {
			for(k=0;k<=C;k++) {
				num[(i*500)+(j*100)+(k*50)]++;
			}
		}
	}
	//printf("%d %d %d %d\n",A,B,C,X);
	printf("%d",num[X]);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&A,&B,&C,&X);
  ^