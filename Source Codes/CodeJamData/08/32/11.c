#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double mod(double a, double b) {
	return (a - (floor(a/b)*b));
}

int main() {
  	int nc, len, c, nloop,i,j,k;
  	char input[50];
  	int comb[50];
  	int val[50];
  	int csign, ugly;
  	double sum, cval;
  	
  	scanf("%d", &nc);
  	for(i=0;i<nc;i++) {
		scanf("%s", input);
		len = strlen(input);
		for(j=0;j<len - 1;j++) comb[j] = 0;
		
		nloop = pow(3, len - 1);
		ugly = 0;
		
		for(k=0;k<nloop;k++) {
				
				sum = 0;
				csign = 1;
				cval = input[0] - '0';
				for(j=0;j<len-1;j++) {
					if (comb[j] == 0) {
						cval = cval*10.0 + (input[j + 1] - '0');
					} else {
						if (csign == 2) cval = -1.0 * cval;
						sum += cval;
						csign = comb[j];
						if (j+1<len)
							cval = input[j + 1] - '0';
						else
							cval = 0;
					}
					
				}
				if (csign == 2) cval = -1 * cval;
				sum += cval;

				if (sum < 0) sum = -sum;

				if ((mod(sum, 2) == 0) || (mod(sum, 3) == 0) || (mod(sum, 5) == 0) || (mod(sum, 7) == 0)) {
					ugly++;
				}
				
				c = 1;
				for(j=len-2;j>=0;j--) {
					comb[j] = comb[j] + c;
					if (comb[j] > 2) {
						comb[j] = 0;
						c = 1;
					} else {
						c = 0;
					}
				}
		}
		
		printf("Case #%d: %d\n", i+1, ugly);
	}
  	
	return 0;
}
