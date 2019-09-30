#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long t, tcount = 1, i,j,k;
long long C,D,V,ans,di,val; //
long long den[1000000];//all denominations

void insert(long long newd) {
	i=D+ans-1;
	while((i>=0) && (den[i] > newd)) {
		den[i+1] = den[i];
		i--;
	}
	den[i+1] = newd;
}

int main()
{
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &C);
        scanf("%lld", &D);
        scanf("%lld", &V);

		scanf("%lld", &den[0]);
		ans = 0;
		if(den[0] != 1) {
			den[1] = den[0];
			den[0] = 1;
			ans++;
		}
		for(i=1; i < D; i++) {
			scanf("%lld", &den[i+ans]);
		}

		val = C;
		di = 1;

		while(val < V) {
			if( (di >= D+ans) || (den[di] > val+1) ) {
				insert(val+1);			
				ans++;
			}
			val += den[di] * C;
			di++;
		}

        printf("Case #%lld: %lld\n", tcount++, ans);
    }
    return 0;
}

