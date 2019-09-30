#include <stdio.h>
#include <stdint.h>
int m[1000];
struct sort_t {
	int id;
	int time;
}sortq[1000];
int main(){
	int t,q;
	scanf("%d", &t);
	for (q=1;q<=t;q++){
		int i, b, n;
		scanf("%d%d", &b, &n);
		int maxm = 0;
		for (i=0;i<b;i++) {
			scanf("%d", m+i);
			if (m[i]>maxm)
				maxm = m[i];
		}
		uint64_t l = 0, r;
		r = (uint64_t)maxm*(uint64_t)(n/b+1);
		uint64_t lval=0,rval=0;
		for (i=0;i<b;i++)
			rval += (r-1)/(uint64_t)m[i]+1;
		while(l<r-1) {
			uint64_t mid = (l+r)/2;
			uint64_t total = 0;
			for (i=0;i<b;i++){
				uint64_t k = (mid-1)/(uint64_t)m[i]+1;
				total += k;
			}
			if (total >= n) {
				r = mid;
				rval = total;
			} else {
				l = mid;
				lval = total;
			}
		}
		int rank = n-lval;
		//r is the exact time when n-1 finish
		for (i=0;i<b;i++)
			if((l%(uint64_t)m[i]) == 0) {
				rank--;
				if (!rank)
					break;
			}
		printf("Case #%d: %d\n", q, i+1);
	}
}
