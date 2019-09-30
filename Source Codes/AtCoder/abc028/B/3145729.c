#include <stdio.h>
#include <string.h>

int cnt[10];

char S[105];

int main(){

	scanf("%s",S);

	int len=strlen(S);

	int i;

	for(i=0;i<len;i++){
	cnt[S[i]-'A']++;
	}

	for(i=0;i<5;i++){
	printf("%d ",cnt[i]);
	}
	printf("%d\n",cnt[5]);

return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^