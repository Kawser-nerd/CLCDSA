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
	s = calloc(sizeof(char),11);
	scanf("%s",s);
	while(*(s+1)){
		if(*s >= '0' && *s <= '9'){
			if(*(s+1) >= '0' && *(s+1) <= '9'){
				printf("%c%c\n", *s,*(s+1));
				return 0;
			}else{
				printf("%c\n", *s);
				return 0;
			}
		}
		s++;
	}
	if(*s >= '0' && *s <= '9'){
		printf("%c\n", *s);
		return 0;
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^