#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define true 1
#define false 0


int main(void){
	char* x;
	int counter = 0;
	int ans = 0;
	x = calloc(sizeof(char),200000);
	scanf("%s",x);
	while(*x){
		if(*x == 'T'){
			if(counter == 0){
				ans++;
			}
			counter = max(0,counter-1);
		}else{
			counter++;
		}
		x++;
	}
	printf("%d\n", ans+counter);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",x);
  ^