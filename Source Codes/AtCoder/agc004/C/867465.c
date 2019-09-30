#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define INF 1000000000
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

long map[500][500];
long red[500][500];
long blue[500][500];

int main() {
	long N;
	long H, W;
	char buf[512];
	long i, j;
	long ans = 0;
	long bottom[500] = {0};
	
	scanf("%ld %ld", &H, &W);
	for(i=0;i<H;i++) {
		scanf("%s", buf);
		for(j=0;j<W;j++) {
			map[i][j] = buf[j] == '#' ? 1 : 0;
		}
	}
	
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			red[i][j] = j == 0 ? 1 : map[i][j];
			blue[i][j] = j == W-1 ? 1 : map[i][j];
		}
	}
	
	for(i=1;i<H-1;i++) {
		for(j=1;j<W-1;j++) {
			if(i % 2) {
				red[i][j] = 1;
			} else {
				blue[i][j] = 1;
			}
		}
	}
	
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			if(red[i][j]) printf("#");
			else printf(".");
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			if(blue[i][j]) printf("#");
			else printf(".");
		}
		printf("\n");
	}
	
	/*
	printf("*** check ***\n");
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			if(red[i][j] && blue[i][j]) printf("#");
			else printf(".");
		}
		printf("\n");
	}
	*/
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld", &H, &W);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", buf);
   ^