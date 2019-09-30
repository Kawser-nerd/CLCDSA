#include <stdio.h>
#include <stdlib.h>

int main(){
	int A, B, N, i, L, sp;
	char res[2];
	scanf("%d%d", &A, &B);
	if(A <= B){
		printf("Impossible\n");
		return 0;
	}
	N = A + B;
	int *next = (int *)malloc(sizeof(int) * N);
	int *is_left = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		next[i] = -1;
		is_left[i] = 1;
	}
	sp = 0;
	L = 0;
	is_left[0] = 0;
	while(L < B){
		for(i = 0; is_left[i] == 0; i++){}
		printf("? %d %d\n", i, sp);
		fflush(stdout);
		scanf("%s", res);
		if(res[0] == 'Y'){
			next[i] = sp;
			is_left[i] = 0;
			sp = i;
			L++;
		}
		else{
			is_left[i] = 0;
			if(L == 0){
				for(sp = 0; is_left[sp] == 0; sp++){}
				is_left[sp] = 0;
			}
			else{
				sp = next[sp];
				L--;
			}
			B--;
		}
	}
	while(next[sp] >= 0){
		sp = next[sp];
	}
	char *s = (char *)malloc(sizeof(char) * (N + 1));
	s[N] = '\0';
	for(i = 0; i < N; i++){
		printf("? %d %d\n", sp, i);
		fflush(stdout);
		scanf("%s", res);
		if(res[0] == 'Y'){
			s[i] = '1';
		}
		else{
			s[i] = '0';
		}
	}
	printf("! %s\n", s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &A, &B);
  ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", res);
   ^
./Main.c:54:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", res);
   ^