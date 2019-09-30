#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i;
	scanf("%d", &N);
	int *s = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		s[i] = 0;
	}
	while(1){
		for(i = 0; i < N; i++){
			printf("%c", (char)((int)'a' + s[i]));
		}
		printf("\n");
		i = N - 1;
		while(1){
			if(s[i] < 2){
				s[i]++;
				break;
			}
			else{
				if(i == 0){
					return 0;
				}
				else{
					s[i] = 0;
					i--;
				}
			}
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^