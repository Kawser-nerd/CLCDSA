#include <stdio.h>

int main(){
	int N,tmp,cnt;
	int i,p,q;

	scanf("%d", &N);
	
        if(N<0 && N>100) return -1;

        int L[N*2];
	for( i=0; i<N*2; i++ ){
		scanf("%d ",&L[i]);
     if (L[i] < 0 || L[i] > 100 ){
      return -1;
    }
	}

	//?????
	for( p = 0; p <( N*2)-1; p++){
		for(q = p + 1; q < (N*2); q++){
			if(L[p] < L[q]){
				tmp = L[p];
				L[p] = L[q];
				L[q] = tmp;
			}
		}
	}

	//?????????
	for( i= 0; i<N*2; i+=2 ){
		cnt += L[i+1];
	}

	printf("%d",cnt);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d ",&L[i]);
   ^