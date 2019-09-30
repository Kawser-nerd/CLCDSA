#include<stdio.h>
#include<math.h>
#include<string.h>
int main() {
	int x,y,z;
	int k,s;
	scanf("%d %d",&k,&s);
	int sum=0;
	for(x=0; x<=k; x++) {
		for(y=0; y<=k; y++) {
			if((s-x-y)<=k&&(s-x-y)>=0) {
				sum++;
			}
		}
	}
	printf("%d",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&k,&s);
  ^