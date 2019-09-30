#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char buffer[100001];
int main(void)
{
	int length;
	int k;
	int cent;

	scanf("%s", buffer);
	length = strlen(buffer);
	cent = length;
	if (length & 1){
		int p = (length) / 2;
		int i;
		for (i = 1; i <= p; ++i){
			if (buffer[p - i] != buffer[p] || buffer[p + i] != buffer[p]){
				cent = 2 * i - 1;
				break;
			}
		}
	}
	else{
		int p = (length) / 2;
		int i;
		for (i = 0; i < p; ++i){
			if (buffer[p - i - 1] != buffer[p] || buffer[p + i] != buffer[p]){
				cent = 2 * i;
				break;
			}
		}
	}
	printf("%d", ((length - cent) / 2 + cent));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", buffer);
  ^