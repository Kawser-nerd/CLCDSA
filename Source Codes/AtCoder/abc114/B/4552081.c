#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	char s[11];
	scanf("%s",s);
	int ans = 999;
	for(int i=0;i<=strlen(s)-3;i++){
		int run = abs((s[i] - '0')*100 + (s[i+1] - '0')*10 + (s[i+2] - '0') - 753);
		if(run < ans) ans = run;
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^