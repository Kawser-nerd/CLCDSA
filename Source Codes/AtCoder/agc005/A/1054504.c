#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N_MAX 200000
#define INF 1145141919
#define SMAP(a, b) ((a)!=(b))&&((a)^=((b)^=((a)^= (b))))

typedef unsigned long long ull;

int i, j;

int n, m;
int k;

int h, w;

char str[N_MAX];

void solve(){
	return;
}

int main (void) {
	char *s = str;
	int result = 0, curr = 0;
	scanf("%s", str);
	while (*s) {
		if (*s == 'T') curr++;
		else curr--;
		if (curr > result) result = curr;
		s++;
	}
	printf("%d\n", result << 1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^