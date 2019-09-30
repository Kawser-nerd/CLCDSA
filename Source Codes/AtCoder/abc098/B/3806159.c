#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int max(int a, int b) { return a >= b ? a : b; }
int min(int a, int b) { return a <= b ? a : b; }
int dsum(int x) { int r=0; while(x){ r+=(x%10); x/=10; } return r;}
int gcd(int a, int b) { int i; for(i=a; i>0; i--) { if(a%i == 0 && b%i == 0) { break; } } return i; }
int lcm(int a, int b) { return (a*b)/gcd(a,b); }
void swap(int *a, int *b) { int tmp; tmp = *a; *a = *b; *b = tmp; return; }

int main(void) {
	int len,ans=0,cnt=0,alph[130]={};
	char s[110];
	scanf("%d%s", &len, s);
	for(int i=1; i<len-1; i++) {
		for(int j='a'; j<='z'; j++) alph[j] = 0;
		for(int j=0; j<i; j++) alph[s[j]] = 1;
		for(int j=i; j<len; j++) {
			if(alph[s[j]]) {
				alph[s[j]] = 0;
				cnt++;
			}
		}
		ans = max(ans,cnt);
		cnt = 0;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%s", &len, s);
  ^