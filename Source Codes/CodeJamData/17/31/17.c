#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int	r;
	int	h;
} RH;

int rhsort(const void *a, const void *b)
{
	RH	*rhA = (RH *)a;
	RH	*rhB = (RH *)b;
	if(2*M_PI*rhB->r*rhB->h > 2*M_PI*rhA->r*rhA->h){
		return 1;
	} else {
		return -1;
	}
}

int main(void)
{
	int		T, N, K;
	RH		rh[1024];
	int		h;
	double	s;
	int		max_r;
	double	max;
	double	base_s;
	
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		h = 0;
		max_r = 0;
		max = 0;
		s = 0;
		scanf("%d %d", &N, &K);
		for(int n=0; n<N; n++){
			scanf("%d %d", &rh[n].r, &rh[n].h);
		}
		qsort((void *)rh, N, sizeof(RH), rhsort);
		for(int k=0; k<K; k++){
			s += 2 * M_PI * rh[k].r * rh[k].h;
			if(max_r < rh[k].r) max_r = rh[k].r;
		}
		base_s = 2 * M_PI * rh[K-1].r * rh[K-1].h   + M_PI * max_r * max_r;
		s += M_PI * max_r * max_r;
		for(int n=K; n<N; n++){
			if(base_s < M_PI * rh[n].r * rh[n].r + 2 * M_PI * rh[n].r * rh[n].h
			&& max < M_PI * rh[n].r * rh[n].r + 2 * M_PI * rh[n].r * rh[n].h && max_r < rh[n].r){
				max = M_PI * rh[n].r * rh[n].r + 2 * M_PI * rh[n].r * rh[n].h;
			}
		}
		if(max > 0){
			s = s - base_s + max;
		}
		printf("Case #%d: %.9f\n", t+1, s);
	}
	
	return 0;
}
