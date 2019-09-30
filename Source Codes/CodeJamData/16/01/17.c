#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BASE 10

char solved(char *seen)
{
	size_t i;

	for(i = 0; i < BASE; i++)
		if(seen[i] != 1)
			return 0;
	
	return 1;
}

void saw(char *seen, unsigned long long int N)
{
	if(N > 0) {
		seen[N % BASE] = 1;
		saw(seen, N / BASE);
	}
}

unsigned int solve(unsigned int N)
{
	char   seen[BASE];
	size_t i;

	bzero(seen, sizeof(seen));

	i = 0;
	while(!solved(seen)) {
		i += N;
		saw(seen, i);
	}

	return i;
}

int main(int argc, char *argv[])
{
	size_t       size;
	size_t       i;
	unsigned int N;

	scanf("%llu", &size);

	for(i = 0; i < size; i++) {
		scanf("%u", &N);

		printf("Case #%u: ", i + 1);

		if(N == 0)
			puts("INSOMNIA");
		else
			printf("%u\n", solve(N));
	}

	return EXIT_SUCCESS;
}
