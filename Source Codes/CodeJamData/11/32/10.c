#include <stdio.h>
#include <string.h>

int main(){
	int T, L, t, N, C, a[1000];
	int K, i, j, k;
	int dis[1000];
	int sum, m1, m2;
	scanf("%d", &T);
	for(K = 1; K <= T; ++K){
		scanf("%d %d %d %d", &L, &t, &N, &C);
		sum = 0;
		for(i = 0; i < C; ++i)
			scanf("%d", &a[i]);
		for(i = 0; i < N; ++i)
			dis[i] = a[i % C] * 2;
		for(i = 0; i < N && sum + dis[i] <= t; ++i)
			sum += dis[i];
		if(i < N){
			dis[i] = sum + dis[i] - t;
			sum = t;
			m1 = m2 = i;
			for(j = i + 1; j < N; ++j){
				if(dis[j] >= dis[m1]){
					m2 = m1;
					m1 = j;
				}else if(dis[j] >= dis[m2])
					m2 = j;
			}
			if(L >= 1) dis[m1] /= 2;
			if(L >= 2 && m2 != m1) dis[m2] /= 2;
			for(; i < N; ++i){
				sum += dis[i];
			}
		}
		printf("Case #%d: %d\n", K, sum);
	}
	return 0;
}
