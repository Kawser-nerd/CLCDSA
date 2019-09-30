#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <regex.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define alloc(type,size) calloc(sizeof(type),size)

#define N 100001

char s[N];
bool f[256];
int res;


int main(void){
	int i;
	char c1,c2;
	char *h;
	scanf("%s",s);
	c1 = *s;
	c2 = *(s+1);
	for(h=s;*h;h++){
		if((h-s)%2){
			if(*h != c2) break;
		}else{
			if(*h != c1) break;
		}
	}
	if(!*h){
		printf("Second\n");
		return 0;
	}
	for(;*h;h++){
		if(*s == *h) res = h-s-2;
		else res = h-s-1;
	}
	printf("%s\n", res%2 ? "First":"Second");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^