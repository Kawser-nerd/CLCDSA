#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/* Reads a number until a ' ' or a '\n' appears */
uint64_t getNumber(FILE *input) {
	uint64_t num=0;
	char c;
	c=getc(input);
	while(c!=10 && c!=32) {num = 10*num+c-48; c=getc(input);}
	return num;
}

int main() {
	FILE *input, *output;
	uint16_t cases;
	input = fopen ("input.in", "r");
	output = fopen ("output.out", "w");
	cases = getNumber(input);
	printf("%d\n",cases);
	for(uint16_t count=1; count<=cases; count++) {
		uint16_t N;
		uint16_t c=0, d;
		N=getNumber(input);
		for(uint16_t i=0; i<N; i++) {
			if(getNumber(input)>i) c++;
		}
		if(c>500) {
			d=c-500;
		} else {
			d=500-c;
		}
		printf("%d\n", d);
		if(d>17) {
			fprintf (output, "Case #%d: BAD\n", count);
		} else {
			fprintf (output, "Case #%d: GOOD\n", count);
		}
		
	}
	return 0;
}
