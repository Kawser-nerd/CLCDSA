#include<stdio.h>
#include<math.h>
#include<string.h>
int main() {
	int n;
	scanf("%d",&n);
	int l=0;
	for(int i=1;i<=n;i++){
		l+=i;
		if(l>=n){
			printf("%d",i);
			break;
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^