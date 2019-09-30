#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

int A,B,C;
int Diff;
long long int K;

int main(){
#ifdef DEBUG
	printf("DEBUGGING ON\n");
#endif
	scanf("%d %d %d %lld", &A,&B,&C,&K);
	Diff=(K%2==0)?(A-B):(B-A);
	printf("%d\n",Diff);
	

	return (0);
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %lld", &A,&B,&C,&K);
  ^