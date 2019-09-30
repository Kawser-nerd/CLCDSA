#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define true 1
#define false 0



int main(void){
	int i;
	char *s;
	int g,p;
	int n = 100004;
	s = calloc(sizeof(char),n);
	g = 0;p = 0;
	scanf("%s",s);
	while(*s!='\0'){
		if(*s == 'g'){
			g++;
		}else{
			p++;
		}
		s++;
	}
	printf("%d\n", (g-p)/2);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^