#include <stdio.h>

int n, m;
int masks[100];
int conditions[100];

int countOne(int n){
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}

int main(){
    int nc, cc;
    scanf(" %d", &nc);
    for(cc = 1; cc <= nc; ++cc){
	int limit, t, i, j;
	int nCond;
	int condPos, condType;

	int min1, minsol;

	scanf(" %d%d", &n, &m);

	for(i = 0; i < m; ++i){
	    scanf(" %d", &nCond);
	    masks[i] = 0; conditions[i] = 0;
	    for(j = 0; j < nCond; ++j){
		scanf(" %d%d", &condPos, &condType);
		masks[i] |= 1 << (condPos - 1);
		conditions[i] |= condType << (condPos - 1);
	    }
	}

	limit = 1 << n;
	min1 = n + 1;
	minsol = -1;
	for(t = 0; t < limit; ++t){
	    int ok = 1;
	    for(i = 0; i < m; ++i)
		if((masks[i] & (t ^ conditions[i])) == masks[i]){
		    ok = 0;
		    break;
		}
	    if(ok){
		int num1 = countOne(t);
		if(num1 < min1){
		    min1 = num1;
		    minsol = t;
		}
	    }
	}

	if(minsol == -1){
	    printf("Case #%d: IMPOSSIBLE\n", cc);
	}else{
	    printf("Case #%d:", cc);
	    for(i = 0; i < n; ++i)
		printf(" %d", minsol & (1 << i) ? 1 : 0);
	    putchar('\n');
	}
    }
    return 0;
}
