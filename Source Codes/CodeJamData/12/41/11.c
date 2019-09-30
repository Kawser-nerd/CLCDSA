#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

long long dist[10240];
long long len[10240];
long long D = 0;

long long ava[10240];

int main(int argc, char *argv[]){
	int T = 0, N = 0;

	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		scanf("%d", &N);
		for (int i = 0; i<N; i++){
			scanf("%lld %lld", &dist[i], &len[i]);
		}
		scanf("%lld", &D);

		memset(ava, 0, sizeof(ava));
		
		ava[0] = dist[0];

		int flag = 0;
		for (int i = 0; i<N && flag == 0; i++){
			if (ava[i] + dist[i] >= D){
				flag = 1;
				break;
			}
			for (int j = i+1; j<N; j++){
				if (ava[i] + dist[i] >= dist[j]){
					long long val = MIN(dist[j] - dist[i], len[j]);
					ava[j] = MAX(ava[j], val);
				}else{
					break;
				}
			}
		}
		if (flag == 0){
			printf("Case #%d: NO\n", cas);
		}else{
			printf("Case #%d: YES\n", cas);
		}
	}
		
	return 0;
}
