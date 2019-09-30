#include <stdio.h>

int main(void) {
	int n,t[100],min;
	scanf ("%d",&n);
	for (int i; i<n ; i++){
		scanf("%d",&t[i]);
	}
	min=t[0];
	for (int i; i<n ; i++){
		if (min>t[i])min=t[i];
	}
	printf("%d\n",min);
	return 0;
		} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t[i]);
   ^