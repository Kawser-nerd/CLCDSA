#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define	abs(a) ((a)<0?-(a):(a))



int main(void){
	char *s;
	s = calloc(sizeof(char),100001);
	int *st;
	int odd = 0;
	int count = 0;
	int i;
	st = calloc(sizeof(int),26);
	st -= 97;
	scanf("%s",s);
	while(*s)st[*s++]++;
	for(i='a';i<='z';i++){
		if(st[i]%2){
			odd++;
			count += st[i] - 1;
		}else{
			count += st[i];
		}
	}
	if(odd){
		count /= 2;
		count /= odd;
		count *= 2;
		count++;
	}
	printf("%d\n", count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^