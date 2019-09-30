#include<stdio.h>
short N, i;
short a, min, max;
int main(){
	scanf("%hd", &N);
	scanf("%hd", &a);
	min=max=a;
	for(i=1; i<N; i++){
		scanf("%hd", &a);
		if(a<min){
			min=a;
		}else if(a>max){
			max=a;
		}
	}
	printf("%d\n", max-min);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd", &N);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd", &a);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd", &a);
   ^