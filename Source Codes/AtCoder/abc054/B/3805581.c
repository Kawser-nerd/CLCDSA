#include<stdio.h>
int N, M, L, f, lx, ly, x, y, i;
char A[51][51], B[51][51];
int main(void){
	scanf("%d %d\n", &N, &M);
	for(i=0; i<N; i++){
		scanf("%s\n", A[i]);
	}
	for(i=0; i<M; i++){
		scanf("%s\n", B[i]);
	}
	L=N-M+1;
	for(lx=0; lx<L; lx++){
		for(ly=0; ly<L; ly++){
			f=1;
			for(y=0; y<M; y++){
				for(x=0; x<M; x++){
					if(A[ly+y][lx+x]!=B[y][x]){f=0; break;}
				}
				if(!f){break;}
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