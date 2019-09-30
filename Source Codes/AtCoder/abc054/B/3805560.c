#include<stdio.h>
int N, M, L, e, f, lx, ly, x, y, i;
char A[51][51], B[51][51];
int main(void){
	scanf("%d %d\n", &N, &M);
	for(i=0; i<N; i++){
		scanf("%s\n", A[i]);
	}
	for(i=0; i<M; i++){
		scanf("%s\n", B[i]);
	}
	e=0;
	for(ly=0; ly<N; ly++){
		for(lx=0; lx<N; lx++){
			if(ly+M-1>=N || lx+M-1>=N){continue;}
			f=1;
			for(int y=0;y<M;++y){
				for(int x=0;x<M;++x){
					if(A[ly+y][lx+x]!=B[y][x]){f=0;}
				}
			}
			if(f){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d\n", &N, &M);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s\n", A[i]);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s\n", B[i]);
   ^