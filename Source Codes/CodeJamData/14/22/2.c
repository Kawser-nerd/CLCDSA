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
		uint64_t A,B,K, num=0;
		A = getNumber(input);
		B = getNumber(input);
		K = getNumber(input);

		if(B>A) {
      uint64_t X;
      X=A;
      A=B;
      B=X;
		}
		if(B<K) {
      num=A*B;
		} else {
      num=A*K;
      for(uint64_t i=K; i<B; i++) {
        for(uint64_t j=0; j<A; j++) {
          if(K>(i&j)) num++;
        }
      }
    }

		fprintf (output, "Case #%d: %ld\n", count, num);


	}
	return 0;
}
