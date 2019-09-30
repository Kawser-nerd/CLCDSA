#include<stdio.h>

int main()
{
	int N;
	int A[222];
	scanf("%d",&N);
	int i;
	for(i=0;i<=N-1;i++)
		scanf("%d",&A[i]);
	int sisuu[222] = {0};
	for(i=0;i<=N-1;i++){
		while(A[i]%2 == 0){
			sisuu[i]++;
			A[i] = A[i] / 2;
		};
	};
	int min = sisuu[0];
	for(i=1;i<=N-1;i++){
		if(min > sisuu[i])	min = sisuu[i];
	};
	printf("%d",min);
		
	
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A[i]);
   ^