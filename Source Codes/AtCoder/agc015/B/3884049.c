#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main() {
	long long int n,m,result=0;
	char str[200005];
	scanf("%s", str);
	m = strlen(str);
	for (int i = 0; i < m; i++) {
		if (str[i] == 'D') { result += i; result += 2 * (m - i-1); }
		else { result += 2 * i ; result +=(m - i-1); }
	}
	printf("%lld", result);
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^