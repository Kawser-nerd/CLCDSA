#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int main(int argc, char **argv){
	if(argc != 2){
		fprintf(stderr, "\e[1;31mERROR: Please specify input.\e[0m\n");
		return 1;
	}
	FILE *f = fopen(argv[1], "r");
	if(!f){
		fprintf(stderr, "\e[1;31mERROR: Could not open file.\e[0m\n");
		return 1;
	}
	uint64_t n;
	fscanf(f, "%"PRIu64"\n", &n);
	for(uint64_t i = 1; i <= n; ++i){
		uint64_t k, c, s;
		fscanf(f, "%"PRIu64" %"PRIu64" %"PRIu64"\n", &k, &c, &s);
		printf("Case #%"PRIu64": ", i);
		if(c*s < k){
			printf("IMPOSSIBLE\n");
			continue;
		}
		for(uint64_t t = 0; t < k; t += c){
			uint64_t a = 1;
			for(uint64_t e = 0, p = 1; e < c && t + e < k; ++e, p *= k){
				a += (t + e)*p;
			}
			printf("%"PRIu64" ", a);
		}
		fputc('\n', stdout);
	}
}