#include <stdio.h>

int main(){
	int H,W;
	scanf("%d %d\n",&H,&W);
	char pix[W];
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j) scanf("%c\n",&pix[j]);
		for(int k = 0; k < 2; ++k){
			for(int j = 0; j < W; ++j) printf("%c",pix[j]);
			printf("\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d\n",&H,&W);
  ^
./Main.c:8:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int j = 0; j < W; ++j) scanf("%c\n",&pix[j]);
                              ^