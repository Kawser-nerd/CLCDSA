#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned t,n;
unsigned s[500];
unsigned idx[500];

int r_sum(unsigned sum1, unsigned sum2, unsigned k) {
	unsigned j;
	if(k==n) {
		return (sum1==sum2 && sum1 != 0);
	}
	if (r_sum(sum1,sum2,k+1)) {
		idx[k]=0; return 1;
	}
	if (r_sum(sum1+s[k],sum2,k+1)) {
		idx[k]=1; return 1;
	}
	if (r_sum(sum1,sum2+s[k],k+1)) {
		idx[k]=2; return 1;
	}
	return 0;
}

int main() {
	unsigned x;
	unsigned i,j;
	
	scanf("%u\n",&t);
	for(i=1; i<=t; i++) {
		//read the testcase
		scanf("%u\n",&n);
		for(j=0; j<n; j++) {
			scanf("%lu\n",&(s[j]));
		}
		//
		printf("Case #%u:\n",i);
		if(r_sum(0,0,0)) {
		for(j=0; j<n; j++) {
			if(idx[j]==1) {
				printf("%u ",s[j]);
			}
		}
		printf("\n");
		for(j=0; j<n; j++) {
			if(idx[j]==2) {
				printf("%u ",s[j]);
			}
		}
		printf("\n");
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}