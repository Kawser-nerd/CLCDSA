#include<stdio.h>

int p[55]={2,7,17,37,47,67,97,107,127,137,157,167,197,227,257,277,307,317,337,347,367,397,457,467,487,547,557,577,587,607,617,647,677,727,757,787,797,827,857,877,887,907,937,947,967,977,997,1087,1097,1117,1187,1217,1237,1277,1297};

int main(){
	int N,i;
	scanf("%d",&N);
	for(i=0;i<N-1;i++)printf("%d ",p[i]);
	printf("%d\n",p[N-1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^