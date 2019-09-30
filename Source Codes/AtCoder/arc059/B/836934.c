#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define INF 10000000000
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int compare_long(const void *a, const void *b) {
	return *(long*)a - *(long*)b;
}

int main() {
	long N;
	char s[100001];
	long i, j;
	long ans = INF;
	long tmp;
	long data[100001];
	long a[101];
	int l = 1, r = 2;
	int count[26] = {0};
	int len;
	
	scanf("%s", s);
	len = strlen(s);
	count[s[l-1] - 'a']++;
	count[s[r-1] - 'a']++;
	while(r <= len) {
		if(count[s[r-1] - 'a'] >= 2) {
			printf("%d %d\n", l, r);
			return 0;
		}
		if(r - l >= 2) {
			count[s[l-1] - 'a']--;
			l++;
		} else {
			r++;
			count[s[r-1] - 'a']++;
		}
	}
	
	printf("-1 -1\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^