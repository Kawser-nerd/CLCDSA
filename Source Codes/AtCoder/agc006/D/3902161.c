#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i;
	scanf("%d", &N);
	int *a = (int *)malloc(sizeof(int) * 2 * N);
	for(i = 1; i < 2 * N; i++){
		scanf("%d", &a[i]);
	}
	int l = 0, h, r = 2 * N, A, B, C, D, f;
	while(r - l > 1){
		h = (l + r) / 2;
		f = -1;
		for(i = 1; i < N; i++){
			A = (a[N - i] >= h ? 1 : 0);
			B = (a[N - i + 1] >= h ? 1 : 0);
			C = (a[N + i - 1] >= h ? 1 : 0);
			D = (a[N + i] >= h ? 1 : 0);
			if(A == B){
				if(A == 1){
					f = 1;
				}
				else{
					f = 0;
				}
				break;
			}
			if(C == D){
				if(C == 1){
					f = 1;
				}
				else{
					f = 0;
				}
				break;
			}
		}
		if(f == -1){
			if(a[1] >= h){
				f = 1;
			}
			else{
				f = 0;
			}
		}
		if(f == 1){
			l = h;
		}
		else{
			r = h;
		}
	}
	printf("%d\n", l);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^