#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

unsigned int
solve(unsigned int rows, unsigned int columns, unsigned int width)
{
	unsigned int i;
	unsigned int count;

	count = 0;
	count = (rows - 1) * (columns / width); // He will cheat anyway

	// We are on the last row now :
	count = count + columns / width; // First hit
	count = count - 1 + width + (columns % width > 0);

	return count;
}

int
main(int argc, char* argv[], char* envp[])
{
	unsigned int T;
	unsigned int R, C, W;

	unsigned int i;

	scanf("%u", &T);

	for(i = 0; i < T; i++) {
		scanf("%u %u %u", &R, &C, &W);
		printf("Case #%d: %d\n", i + 1, solve(R, C, W));
	}

	return EXIT_SUCCESS;
}
