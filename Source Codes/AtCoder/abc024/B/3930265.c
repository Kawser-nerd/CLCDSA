#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int n,t,a[100005],res;
	scanf("%d%d",&n,&t);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	
	for (int i=0;i<n;i++){
	    if (i!=n-1){
	        if (a[i+1]>a[i]+t){
	            res += t;
	        }else{
	            res += (a[i+1]-a[i]);
	        }
	    }else{
	        res += t;
	    }
	}
	printf("%d\n",res);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&t);
  ^
./Main.c:9:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (int i=0;i<n;i++) scanf("%d",&a[i]);
                        ^