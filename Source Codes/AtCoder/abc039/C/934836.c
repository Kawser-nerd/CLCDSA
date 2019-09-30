#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define	abs(a) ((a)<0?-(a):(a))

//WBWBWWBWBWBW

int main(void){
	char *s;
	s = calloc(sizeof(char),21);
	scanf("%s",s);
	if(!strcmp(s,"WBWBWWBWBWBWWBWBWWBW")){
		printf("Do\n");
	}else if(!strcmp(s,"WBWWBWBWBWWBWBWWBWBW")){
		printf("Re\n");
	}else if(!strcmp(s,"WWBWBWBWWBWBWWBWBWBW")){
		printf("Mi\n");
	}else if(!strcmp(s,"WBWBWBWWBWBWWBWBWBWW")){
		printf("Fa\n");
	}else if(!strcmp(s,"WBWBWWBWBWWBWBWBWWBW")){
		printf("So\n");
	}else if(!strcmp(s,"WBWWBWBWWBWBWBWWBWBW")){
		printf("La\n");
	}else if(!strcmp(s,"WWBWBWWBWBWBWWBWBWWB")){
		printf("Si\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^