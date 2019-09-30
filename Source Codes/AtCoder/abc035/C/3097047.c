#include <stdio.h>

int table[200005];

int main() {

	int N,Q;

	scanf("%d %d",&N,&Q);

	int i;

	for(i=0;i<Q;i++){
	int l,r;
	scanf("%d %d",&l,&r);
	l--;
	r--;
	table[l]++;
	table[r+1]--;
	}

	for(i=0;i<N;i++){
		if(i>0){table[i]+=table[i-1];}
	}
	for(i=0;i<N;i++){
	printf("%d",table[i]%2);
	}
	printf("\n");

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&Q);
  ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&l,&r);
  ^