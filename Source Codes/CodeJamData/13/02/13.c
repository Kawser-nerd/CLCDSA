#include <stdio.h>

int main()
{
	int cas, cas_n, N, M, i, j, k, flag;
	int lawn[128][128];
	scanf("%d", &cas_n);
	for(cas=1; cas<=cas_n; cas++) {
		scanf("%d %d", &N, &M);
		for(i=0; i<N; i++)
			for(j=0; j<M; j++)
				scanf("%d", &lawn[i][j]);
		
		flag = 0;
		for(i=0; i<N; i++) {
			for(j=0; j<M; j++) {
				flag = 0;
				for(k=0; k<N; k++)
					if(lawn[k][j] > lawn[i][j]) {
						flag++;
						break;
					}
				for(k=0; k<M; k++)
					if(lawn[i][k] > lawn[i][j]) {
						flag++;
						break;
					}
				if( flag >= 2 )
					goto CHECK_END;
			}
		}
		CHECK_END:
		if( i==N && j==M )
			printf("Case #%d: YES\n", cas);
		else
			printf("Case #%d: NO\n", cas);
	}
}
