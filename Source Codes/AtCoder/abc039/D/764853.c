#include <stdio.h>
#include <stdlib.h>

int main(void){
	int w, h, i, j, k, l, c;
	char *after, *before, *t;

	scanf("%d %d", &h, &w);

	after = (char *) malloc(10001);
	before = (char *) malloc(10001);
	t = (char *)malloc(10001);

	for(i = 0; i < h; i++){
		scanf("%s", after + w * i);
	}

	for(j = 0; j < h; j++){
		for(i = 0; i < w; i++){
			t[j * w + i] = after[j * w + i] == '.' ? -1 : 0;
		}
	}

	for(j = 0; j < h; j++){
		for(i = 0; i < w; i++){
			c = 0;
			for(l = j - 1; l <= j + 1; l++){
				for(k = i - 1; k <= i + 1; k++){
					if(0 <= k && k < w &&
					   0 <= l && l <= h){
						if(after[l * w + k] == '.') c++;
					}
				}
			}
			if(c == 0)
				for(l = j - 1; l <= j + 1; l++)
					for(k = i - 1; k <= i + 1; k++)
						if(0 <= k && k < w &&
						   0 <= l && l <= h)
							t[l * w + k]++;
			before[w * j + i] = c == 0 ? '#' : '.';
		}
	}

	for(j = 0; j < h; j++){
		for(i = 0; i < w; i++){
			if(t[j * w + i] == 0){
				printf("impossible\n");
				return 0;
			}
		}
	}
	

	printf("possible\n");
	for(j = 0; j < h; j++){
		for(i = 0; i < w; i++){
			printf("%c", before[j * w + i]);
		}
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &h, &w);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", after + w * i);
   ^