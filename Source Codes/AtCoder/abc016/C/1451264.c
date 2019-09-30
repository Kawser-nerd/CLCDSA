#include <stdio.h>

typedef struct {
	int a;
	int b;
} sns_t;

int main(int argc, char *argv[])
{
	int i, j, k, N, M, n;
	sns_t s[100];
	scanf("%d %d", &N, &M);
	for ( i = 0; i < M; i++ ){
		scanf("%d %d", &s[i].a, &s[i].b);
	}
	for ( i = 1; i <= N; i++ ){
		int list[11] = {0};
		for ( j = 0; j < M; j++ ){
			if ( s[j].a == i ){
				list[ s[j].b ] = 1;
			}
			if ( s[j].b == i ){
				list[ s[j].a ] = 1;
			}
		}
		for ( n = 0, j = 1; j <= 10; j++ ){
			if ( list[j] != 1 ){
				continue;
			}
			for ( k = 0; k < M; k++ ){
				if ( s[k].a == j && s[k].b != i && list[ s[k].b ] == 0 ){
					list[ s[k].b ] = 2;
					n++;
				}
				if ( s[k].b == j && s[k].a != i && list[ s[k].a ] == 0 ){
					list[ s[k].a ] = 2;
					n++;
				}
			}
		}
		printf("%d\n", n);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &M);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &s[i].a, &s[i].b);
   ^