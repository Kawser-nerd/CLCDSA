#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i, f = 0, ans = 0;
	scanf("%d",&N);
	int *p = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &p[i]);
		p[i]--;
	}
	for(i = 0; i < N; i++){
		if(p[i] == i){
			if(f == 0){
				ans++;
				f = 1;
			}
			else{
				f = 0;
			}
		}
		else{
			f = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &p[i]);
   ^