//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char buffer[200003] = { 0 };
int count[26] = { 0 };
int f(char c)
{
	return (c < 'a' || 'z' < c) ? 0 : 1;
}
int main(void)
{
	int i, cnt;
	long long answer;
	fgets(buffer, sizeof(buffer), stdin);
	for (cnt = 0; f(buffer[cnt]); ++cnt){
		count[buffer[cnt] - 'a']++;
	}
	answer = cnt * ((long long)cnt - 1) / 2 + 1;
	for (i = 0; i < 26; ++i){
		answer += -count[i] * ((long long)count[i] - 1) / 2;
	}
	printf("%lld\n", answer);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(buffer, sizeof(buffer), stdin);
  ^