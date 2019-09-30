#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, D1, D2, i, j, k, l, f, g;
	scanf("%d%d%d", &N, &D1, &D2);
	for(k = 0; D1 % 2 == 0; D1 /= 2, k++){}
	for(l = 0; D2 % 2 == 0; D2 /= 2, l++){}
	int num = 0;
	for(i = 0; i < 2 * N; i++){
		for(j = 0; j < 2 * N; j++){
			if(num == N * N){
				return 0;
			}
			if(((k % 2 == 0 && ((i / (1 << (k / 2))) + (j / (1 << (k / 2)))) % 2 == 0) || (k % 2 == 1 && (i / (1 << (k / 2))) % 2 == 0)) && ((l % 2 == 0 && ((i / (1 << (l / 2))) + (j / (1 << (l / 2)))) % 2 == 0) || (l % 2 == 1 && (i / (1 << (l / 2))) % 2 == 0))){
				printf("%d %d\n", i, j);
				num++;
			}
/*			if(k % 2 == 0){
				if(((i / (1 << (k / 2))) + (j / (1 << (k / 2)))) % 2 == 0){
					f = 0;
				}
				else{
					f = 1;
				}
			}
			else{
				if((i / (1 << (k / 2))) % 2 == 0){
					f = 0;
				}
				else{
					f = 1;
				}
			}
			if(l % 2 == 0){
				if(((i / (1 << (l / 2))) + (j / (1 << (l / 2)))) % 2 == 0){
					g = 0;
				}
				else{
					g = 1;
				}
			}
			else{
				if((i / (1 << (l / 2))) % 2 == 0){
					g = 0;
				}
				else{
					g = 1;
				}
			}
			if(f == 0 && g == 0){
				printf("%d %d\n", i, j);
				num++;
			}
*/		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &D1, &D2);
  ^