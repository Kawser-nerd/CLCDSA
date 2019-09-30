#define _POSIX_C_SOURCE 201604L//enable getline

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
	char *line = NULL;
	size_t line_len = 0;
	if(getline(&line, &line_len, f) == -1){
		fprintf(stderr, "\e[1;31mERROR: Could not read file.\e[0m\n");
		free(line);
		fclose(f);
		return 1;
	}
	char *end;
	uint64_t n = strtoll(line, &end, 10);
	if(end == line){
		fprintf(stderr, "\e[1;31mERROR: Could not read number.\e[0m\n");
		free(line);
		fclose(f);
		return 1;
	}
	for(uint64_t i = 1; i <= n; ++i){
		if(getline(&line, &line_len, f) == -1){
			fprintf(stderr, "\e[1;31mERROR: Missing lines.\e[0m\n");
			free(line);
			fclose(f);
			return 1;
		}
		uint64_t a = strtoll(line, &end, 10);
		if(end == line){
			fprintf(stderr, "\e[1;31mERROR: Missing numbers.\e[0m\n");
			free(line);
			fclose(f);
			return 1;
		}
		if(!a){
			printf("Case #%"PRIu64": INSOMNIA\n", i);
			continue;
		}
		uint64_t digit_mask = 0x3FF, m = 0;
		while(m <= UINT64_MAX - a){
			m += a;
			for(uint64_t t = m; t; t /= 10){
				digit_mask &= (int64_t)0xFFFFFFFFFDFF >> t%10;
			}
			if(!digit_mask){
				break;
			}
		}
		if(digit_mask){
			printf("Case #%"PRIu64": INSOMNIA\n", i);
		}else{
			printf("Case #%"PRIu64": %"PRIu64"\n", i, m);
		}
	}
}

