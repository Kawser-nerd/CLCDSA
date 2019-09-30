#include <stdio.h>

int main(){
	int n,a;
	scanf("%d",&n);
	scanf("%d",&a);
	int x = n%500;
	if(x>a){
		printf("No");
	}else{
		printf("Yes");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^