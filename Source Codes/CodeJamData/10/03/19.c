#include<stdio.h>
#include<stdlib.h>

long make_money(long R, long k, int N, long *g) {
	long step;
	long start, end;
	long *b, *index;
	long csum;
	int groups;
	long totalmoney;

	int i, j;
	long bcap = N;
	int loopflag = 0;

	index = (long *)malloc(sizeof(long)*N);
	b = (long *)malloc(sizeof(long)*(N+1));
	for(i = 0; i < N; i++) {
		b[i] = 0;
		index[i] =0;
	}
	step = 1;
	index[0] = step;
	j = 0;
	while(step <= R) {
		if(step > bcap) {
			b = (long *)realloc(b, sizeof(long)*((bcap+N)+1));
			bcap += N;
		}
		csum = 0;
		groups = 0;
		while(csum <= k && groups != N) {
			csum += g[j];
			groups++;
			j = (j + 1) % N;
		}
		if(csum > k) {
			j = (j==0) ? (N-1) : (j-1);
			csum -= g[j];
		}
		b[step] = b[step - 1] + csum;
		if(loopflag) {
			break;
		}
		step++;
		if(index[j] == 0) {
			index[j] = step;
		} else {
			start = index[j];
			end = step;
			loopflag = 1;
		}
	}
/*	
printf("%ld, %ld\n", start, end);
printf("%ld\n", step);
int ii;
for(ii = 0; ii < bcap+1; ii++)
	printf("%ld ", b[ii]);
	*/
	if(step > R) {
		totalmoney = b[R];
	} else {
		long loopcount = end - start;
		long loopmoney = b[end] - b[start];
		long totalloopmoney = ((R - start) / loopcount)*loopmoney;
		long redundancy = b[start + (R - start) % loopcount] - b[start];
		totalmoney = b[start] + totalloopmoney + redundancy;
	}

	free(b);
	free(index);
	return totalmoney;
}

int main(int argc, char **argv) {
	int T;

	long R, k;
	int N;
	long *g;

	int i, j;

	scanf("%d\n", &T);

	for(i = 0; i < T; i++) {
		scanf("%ld %ld %d\n", &R, &k, &N);
		g = (long *)malloc(sizeof(long) * N);
//printf("%ld %ld %d\n", R, k, N);
		for(j = 0; j < N; j++) {
			scanf("%ld", &g[j]);
//printf("%ld ", g[i]);
		}
//printf("\n");
		printf("Case #%d: %ld\n", i+1, make_money(R, k, N, g));
		free(g);
	}
}
