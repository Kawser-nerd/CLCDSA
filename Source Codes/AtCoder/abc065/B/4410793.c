#include <stdio.h>

int main(void){

	int N;
	int a[100000];

	scanf("%d", &N);

	int i;
	
	for(i = 1; i <= N; i++){
		scanf("%d", &a[i]);
	}

	int X = 1;
	int count = 0;

	while(X != 2){				
		count++;
		X = a[X];

		if(count == 10 * N){
			break;
	
		}
		
	}

    if(count == 10 * N) count = -1;
	printf("%d\n", count);

	return 0;

} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^