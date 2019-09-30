#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int a[100005],res,x,n;
	res = 0;
	scanf("%d",&n);
	for (int i=0;i<100005;i++){
	    a[i]=0;
	}
	for (int i=0;i<n;i++){
	    scanf("%d",&x);
	    a[x]+=1;
	}
	
	for (int i=0;i<100005;i++){
	    if (a[i]>1) res += a[i]-1;
	}
	printf("%d\n",res);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:14:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d",&x);
      ^