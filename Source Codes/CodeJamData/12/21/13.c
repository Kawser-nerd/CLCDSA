#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Block.h>

int main() {
	unsigned t,n;
	unsigned x;
	unsigned i,j,k;

	unsigned s[200];
	unsigned s_sort[201];
	unsigned mins, minss;
	double yjm,yt,yadd;
	unsigned passed_me;
	unsigned nsplit;
	
	scanf("%u\n",&t);
	for(i=1; i<=t; i++) {
		//read the testcase
		scanf("%u\n",&n);
		x = 0;
		mins=100; minss=100;
		for(j=0; j<n; j++) {
			scanf("%lu\n",&(s[j]));
			x += s[j]; s_sort[j] = s[j];
			if(s[j] <= mins) {
				minss = mins;
				mins = s[j];
			}
		}
		qsort_b(s_sort,n,sizeof(unsigned),^(const void *l, const void *r) {
			unsigned left = *(unsigned *)l;
			unsigned right = *(unsigned *)r;
			if(left>right) { return 1;
			} else if (left==right) { return 0;
			}
			return -1;
		});
		s_sort[n] = s_sort[n-1];

		//
		printf("Case #%u:",i);
		for(j=0; j<n; j++) {
			passed_me = 0;
			yjm = 0; yt = 0;
			for (k=0; k<n; k++) {
				//if(s_sort[k]==s[j] && !passed_me) { passed_me = 1; continue; }
				passed_me = s_sort[k]>=s[j];
				yadd = ((double)s_sort[k+1]-s_sort[k])/x;
				if(yadd==0) { continue; }
				if(yt+yadd*(k+1) > 1) {
					yadd = (1.0-yt)/(k+1);
					if(passed_me)
						yjm += yadd; yt = 1;
					break;
				} else {
					yt += yadd*(k+1);
					if(passed_me)
						yjm += yadd;
				}
			}
			if(yt < 1) {
				yadd = (1.0-yt)/n;
				yjm += yadd;
			}
//			if (s[j]!=mins) {
//				yjm = 1-(double)(s[j]-mins)/x;
//			} else {
//				yjm = 1-((double)s[j]-minss)/x;
//			}
//			yjm /= 2;
			printf(" %f",yjm*100);
		}

		printf("\n");
	}
	return 0;
}