#include<stdio.h>

int main()
{
	int N, M, X, Y;
	int friend[12];
	int i, j, flag, size;
	int ret;
	
	scanf("%d %d", &N, &M);
	
	for(i = 0; i < N; i++) {
		friend[i] = 1 << i;
	}
	
	for(i = 0; i < M; i++) {
		scanf("%d %d", &X, &Y);
		--X, --Y;
		friend[X] |= 1 << Y;
		friend[Y] |= 1 << X;
	}

	ret = 0;
	for(i = 0; i < (1 << N); i++) {
		flag = 1;
		size = 0;
		for(j = 0; j < N; j++) {
			if((i >> j) & 1) {
				if(i & ~friend[j]) flag = 0;
				++size;
			}
		}
		if(flag == 1) {
			if(size > ret) {
				ret = size;
			}
		}
	}

	printf("%d\n", ret);
	
	return(0);
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &M);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &X, &Y);
   ^