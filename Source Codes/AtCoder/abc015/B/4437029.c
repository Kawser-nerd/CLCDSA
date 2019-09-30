#include <stdio.h>
#include <math.h>
int main(void){
	int n,n2=0,a,b=0,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(a!=0){
			b+=a;
			n2++;
		}
	}
	printf("%d\n",(int)ceil((float)b/n2));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^