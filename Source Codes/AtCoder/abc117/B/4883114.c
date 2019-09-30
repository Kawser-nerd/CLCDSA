#include <stdio.h>

int main(void){
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	int max = 0;
	int sum = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(max < a[i])max = a[i];
		sum += a[i];
	}
	//???????max*2???????0????ok
	if( sum-max*2 >0){
		printf("Yes");
	}else{
		printf("No");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^