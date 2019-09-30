#include <stdio.h>
int main(void){
	int N,Q;
	int i,j;
	int l,r;

	scanf("%d %d",&N,&Q);
	int st[N];
	for(i=0;i<N;i++){
		st[i] = 1; //1?????0
		
	}

	for(i=0;i<Q;i++){
		scanf("%d %d",&l,&r);
		st[l-1] *= -1;
		st[r] *= -1;
	}
	for(i=1;i<N;i++){
		st[i] *= st[i-1];
	}

	for(i=0;i<N;i++){
		if(st[i] == 1){
			printf("0");
		}else{
			printf("1");
		}
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&Q);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&l,&r);
   ^