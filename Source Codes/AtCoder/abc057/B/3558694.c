#include<stdio.h>
int main()

{
	int N, M;
	scanf("%d %d", &N, &M);
	
	int x, y; //????
	
	int a[N];
	int b[N];
	int c[M];
	int d[M];
	
	for(x=0; x<N; x++) scanf("%d %d", &a[x], &b[x]);
	for(x=0; x<M; x++) scanf("%d %d", &c[x], &d[x]);
	
	int e[N];
	int j, k, l;
	
	for(x=0; x<N; x++) e[x] = 0;
	
	for(x=0; x<N; x++){
		l = 1000000000;
		for(y=0; y<M; y++)
		{
			j = a[x]-c[y];
			k = b[x]-d[y];
			if(j < 0) j = -j;
			if (k < 0) k = -k;
			if(j+k < l){
				l = j+k;
				e[x] = y+1;
			}
		}
	}
	
		
		for(x=0; x<N; x++) printf("%d\n", e[x]);
		
		return 0;
		} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &M);
  ^
./Main.c:15:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(x=0; x<N; x++) scanf("%d %d", &a[x], &b[x]);
                     ^
./Main.c:16:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(x=0; x<M; x++) scanf("%d %d", &c[x], &d[x]);
                     ^