#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define lli long long int
#define min(x,y) ((a)<(b)?(a):(b))
#define max(x,y) ((a)>(b)?(a):(b))
#define true 1
#define false 0


int main(void){
	int i,j;
	int h,w,w1;
	char **a;
	char **r;
	char **b;
	scanf("%d%d",&h,&w);
	a = calloc(sizeof(char*),h);
	r = calloc(sizeof(char*),h);
	b = calloc(sizeof(char*),h);
	for(i=0;i<h;i++){
		a[i] = calloc(sizeof(char),w);
		r[i] = calloc(sizeof(char),w);
		b[i] = calloc(sizeof(char),w);
		scanf("%s",a[i]);
	}
	for(i=0;i<h;i++){
		w1 = w-1;
		b[i][0] = '.';
		b[i][w1] = '#';
		r[i][0] = '#';
		r[i][w1] = '.';
		if(i%2){
			for(j=1;j<w-1;j++){
				b[i][j] = '#';
				r[i][j] = a[i][j];
			}
		}else{
			for(j=1;j<w-1;j++){
				r[i][j] = '#';
				b[i][j] = a[i][j];
			}
		}
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			printf("%c", r[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			printf("%c", b[i][j]);
		}
		printf("\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a[i]);
   ^