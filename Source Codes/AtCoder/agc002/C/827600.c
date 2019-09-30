#include <stdio.h>

#define MAX_N 100010

int main(void) {
	int n,L,a[MAX_N];
	int i,sum[MAX_N],min,minnum;
	
	scanf("%d %d", &n,&L);
	
	for (i=1;i<=n;i++) 
		scanf("%d", &a[i]);
	
	min=0;
	for (i=1;i<n;i++) {
		sum[i]=a[i]+a[i+1];
		if (min<sum[i]) {
			min=sum[i];
			minnum=i;
		}
	}
	
	if (min<L) 
		printf("Impossible\n");
	else {
		printf("Possible\n");
		for (i=1;i<minnum;i++) 
			printf("%d\n", i);
		for (i=n-1;i>minnum;i--)
			printf("%d\n", i);
		printf("%d\n", minnum);
	}
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n,&L);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^