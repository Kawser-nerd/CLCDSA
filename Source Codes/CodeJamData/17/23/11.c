#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NMAX 100
#define QMAX 100

struct horse {
	unsigned long int /* Ei */ distance;
	unsigned int      /* Si */ speed;
};

struct path {
	char /* Uk */ from;
	char /* Vk */ to;
};

double solve(struct horse *horses, size_t matrix[NMAX][NMAX], size_t n,
             struct path  *paths, size_t q)
{
	size_t city, i;
	size_t distance, total;
	
	double best[NMAX];
	double try;
	
	/* Focus on the small dataset ; q = 1 */
	assert(q == 1);

	
	/* Fill with the highest score possible */
	for(i = 0; i < NMAX; i++)
		best[i] = 1e99;

	best[0] = 0;

	/* Find where we can go from each horse */
	for(city = 0; city < n; city++) {
		distance = 0;
		assert(best[city] != -1);
		
		for(i = city + 1; i < n; i++) {
			assert(matrix[i - 1][i] != -1);

			distance += matrix[i - 1][i];
			/* Horse ran out of stamina */
			if(distance > horses[city].distance)
				break;
                
			/* Is it better to leave city with its horse ? */
			try = (double)distance / horses[city].speed;
			if(best[i] > try + best[city])
				best[i] = try + best[city];
		}
	}

	return (double)best[n - 1];
}

int main(int argc, char *argv[])
{
	size_t T, i;
	size_t N, j, Q, k;

	double answer;
	struct horse horses[NMAX];
	size_t cities[NMAX][NMAX];
	struct path paths[QMAX];

	scanf("%llu", &T);
	for(i = 0; i < T; i++) {
		scanf("%llu %llu", &N, &Q);

		/* Read each horses */
		for(j = 0; j < N; j++)
			scanf("%llu %u", &horses[j].distance,
			                 &horses[j].speed);

		/* Read each cities */
		for(j = 0; j < N; j++)
			for(k = 0; k < N; k++)
				scanf("%llu", &cities[j][k]);

		for(j = 0; j < Q; j++)
			scanf("%u %u", &paths[j].from, &paths[j].to);
		
		answer = solve(horses, cities, N, paths, Q);
		printf("Case #%u: %.6f\n", i + 1, answer);
	}

	return EXIT_SUCCESS;
}