#include <stdio.h>
#include <stdlib.h>

#define NMAX 1000

struct horse {
	unsigned int position;
	unsigned int speed;
};

double solve(size_t distance, struct horse *horses, size_t n)
{
	size_t i;
	size_t maxDelta = distance - horses[0].position;
	size_t maxSpeed = horses[0].speed;

	/* Determine how long it takes for the slowest horse to end */
	for(i = 1; i < n; i++) {
		size_t delta = distance - horses[i].position;
		size_t speed = horses[i].speed;

		/**
		 * Double may create approximation errors, so use ints instead
		 * A <=> maxDelta / maxSpeed < delta / speed
		 * A <=> maxDelta * speed < delta * maxSpeed
		 */
		if(maxDelta * speed < delta * maxSpeed) {
			maxDelta = delta;
			maxSpeed = speed;
		}
	}

	return distance * maxSpeed / (double)maxDelta;
}

int main(int argc, char *argv[])
{
	size_t i, T;
	size_t D, N, j;
	double answer;
	struct horse horses[NMAX];

	scanf("%llu", &T);
	for(i = 0; i < T; i++) {
		scanf("%llu %llu", &D, &N);

		for(j = 0; j < N; j++)
			scanf("%u %u", &horses[j].position, &horses[j].speed);

		answer = solve(D, horses, N);
		printf("Case #%u: %.6f\n", i + 1, answer);
	}

	return EXIT_SUCCESS;
}