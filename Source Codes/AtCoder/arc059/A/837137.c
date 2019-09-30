#include <stdio.h>
int main(void){

	int i;
	int N;
	scanf("%d", &N);
	int num[N], sum=0, ave;
	int ans1=0, ans2=0;

	for(i=0; i<N; i++){
		scanf("%d", &num[i]);
	}

	for(i=0; i<N; i++){
		sum += num[i];
	}

	ave = sum / N;
	
	for(i=0; i<N; i++){
		ans1 += (num[i] - ave) * (num[i] - ave);
		ans2 += (num[i] - ave -1) * (num[i] - ave -1); 
	}

	if(ans1>ans2){
		printf("%d\n", ans2);
	}else{
		printf("%d\n", ans1);
	}



	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &num[i]);
   ^