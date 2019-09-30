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
		char c[200][200], test;
		int32_t n[200][200], strings, stringlength[200], solvable=0;
		strings = getNumber(input);
		for(uint16_t i=0; i<strings; i++) {
      c[i][0] = 0;
      n[i][0] = 0;
      stringlength[i] = -1;
      test=getc(input);
      while(test!=10) {
        if(stringlength[i] == -1) {stringlength[i] = 0; c[i][0]=test; c[i][1]=0;}
        if(c[i][stringlength[i]] == test) {
          n[i][stringlength[i]]++;
        } else {
          stringlength[i]++;
          c[i][stringlength[i]] = test;
          c[i][stringlength[i]+1] = 0;
          n[i][stringlength[i]] = 1;
        }

        test=getc(input);
      }
		}
    for(uint16_t i=0; i<strings; i++) {
      if(stringlength[0]!=stringlength[i]) solvable=-1;
    }
    for(uint16_t j=0; j<=stringlength[0]; j++) {
      for(uint16_t i=0; i<strings; i++) {
        if(c[i][j]!=c[0][j]) solvable=-1;
      }
    }if(solvable!=-1) {
      for(uint16_t j=0; j<=stringlength[0]; j++) {
        uint16_t min=0, max=n[0][j];
        for(uint16_t i=0; i<strings; i++) {if(max<n[i][j]) max=n[i][j];}
        for(uint16_t i=0; i<strings; i++) {
          min += n[i][j];
        }
        for(uint16_t k=0; k<=max; k++) {
          uint16_t summe=0;
          for(uint16_t i=0; i<strings; i++) {
            if(n[i][j]>k) {
              summe += n[i][j]-k;
            } else {
              summe += k-n[i][j];
            }
          }
          if(summe<min) min=summe;
        }
        solvable += min;
      }
    }
    fprintf (output, "Case #%d: ", count);
    if(solvable==-1) {
      fprintf (output, "Fegla Won\n");
    } else {
      fprintf (output, "%d\n", solvable);
    }




	}
	return 0;
}
