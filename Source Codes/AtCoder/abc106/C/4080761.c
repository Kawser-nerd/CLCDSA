#include <stdio.h>

int main(void)
{
	char s[102];
	long long k,i;
	scanf("%s",s);
	scanf("%lld",&k);

	for (i=0;i<k;i++) {
		if (s[i]=='1') continue;
		i++;
		break;
	}
	i--;
	printf("%c\n",s[i]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&k);
  ^