#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i, j, k, l, m, now, ans;
	char b[4] = {'A', 'B', 'X', 'Y'};
	char L[2], R[2];
	scanf("%d", &N);
	char *S = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S);
	ans = N;
	for(j = 0; j < 4; j++){
		for(k = 0; k < 4; k++){
			for(l = 0; l < 4; l++){
				for(m = 0; m < 4; m++){
					L[0] = b[j];
					L[1] = b[k];
					R[0] = b[l];
					R[1] = b[m];
					now = 0;
					for(i = 0; i < N; i++){
						if(i == N - 1){
							now++;
						}
						else if(S[i] == L[0] && S[i + 1] == L[1]){
							now++;
							i++;
						}
						else if(S[i] == R[0] && S[i + 1] == R[1]){
							now++;
							i++;
						}
						else{
							now++;
						}
					}
					if(ans > now){
						ans = now;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^