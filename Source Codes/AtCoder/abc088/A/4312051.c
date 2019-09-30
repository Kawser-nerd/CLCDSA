#include <stdio.h>

int main(){
	int a,n,i,m;
	scanf("%d",&n);
	scanf("%d",&a);
	m = n/500;
	for (i=0;i<m;i++) {
		n = n - 500;
	}
	if (a >= n){
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^