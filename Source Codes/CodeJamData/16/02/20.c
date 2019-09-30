#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define T 100

unsigned int solve(char *buffer)
{
	unsigned int ret;
	size_t       size;
	size_t       i;
	char         old;

	size = strlen(buffer);
	old  = buffer[0];
	ret  = 0;

	for(i = 0; i < size; i++) {
		if(buffer[i] != old) {
			old = buffer[i];
			ret++;
		}
	}

	if(buffer[size - 1] == '-')
		ret++;

	return ret;
}

int main(int argc, char *argv[])
{
	size_t size;
	size_t i;
	char   buffer[T + 1];

	scanf("%llu", &size);

	for(i = 0; i < size; i++) {
		scanf("%100s", buffer);
		printf("Case #%u: %u\n", i + 1, solve(buffer));
	}

	return EXIT_SUCCESS;
}
