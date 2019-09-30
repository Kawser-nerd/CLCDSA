#include<stdio.h>
short H, W, i, j;
char A[100][101];
int main(){
	scanf("%hd %hd\n", &H, &W);
	for(i=-2; i<W; ++i){
		putchar('#');
	}
	putchar(10);
	for(j=0; j<H; j++){
		putchar('#');
		for(i=0; i<W; ++i){
			putchar(getchar());
		}
		putchar('#');
		putchar(getchar());
	}
	for(i=-2; i<W; ++i){
		putchar('#');
	}
	putchar(10);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd %hd\n", &H, &W);
  ^