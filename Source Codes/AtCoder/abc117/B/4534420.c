#include <stdio.h>
int main(void){
	int n,i,max=0,sum=0,L;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&L);
		sum += L;
		if(L>max){
			sum += max;
			max = L;
			sum -= max;
		}
	}
	if(max < sum)printf("Yes");
	else printf("No");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&L);
   ^