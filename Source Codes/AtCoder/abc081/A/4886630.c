#include<stdio.h>

int main(void) {
	int cnt=0;
	char c;
	for(int i=0;i<3;i++) {
		scanf("%c",&c);
		if(c=='1')
			cnt++;
	}
	printf("%d",cnt);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&c);
   ^