#include <stdio.h>
#include <stdlib.h>

int main(void){
	int h, w;
	char *u, *v;
	scanf("%d %d", &h, &w);
	u = malloc(sizeof(char) * h);
	v = malloc(sizeof(char) * w);
	for(int i = 0; i < h; i++)u[i] = 0;
	for(int i = 0; i < w; i++)v[i] = 0;
	char **block = malloc(sizeof(char *) * h);
	for(int i = 0; i < h; i++){
		block[i] = malloc(sizeof(char) * (w + 1));
		scanf("%s", block[i]);
		for(int j = 0; j < w; j++){
			if(block[i][j] == '#'){
				u[i]++;
				v[j]++;
			}
		}
	}
	for(int i = 0; i < h; i++){
		if(u[i] == 0)continue;
		for(int j = 0; j < w; j++){
			if(v[j] > 0)printf("%c", block[i][j]);
		}
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &h, &w);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", block[i]);
   ^