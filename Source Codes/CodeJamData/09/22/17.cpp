// Adrian Kügel
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <assert.h>
#include <limits.h>
#include <complex>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;

typedef set<int> SI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef complex<double> tComp;

int main() {
	int tc;
	char n[100];
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d: ", scen);
		scanf("%s", n);
		assert(n[0] != '0');
		int l = strlen(n);
		int d[10] = {0};
		for (int i=0; i<l;++i)
			++d[n[i]-'0'];
/*		char comp[100];
		int N;
		sscanf(n, "%d", &N);
		while(1) {
			++N;
			int l2 = sprintf(comp, "%d", N);
			int d2[10] = {0};
			for (int i=0; i<l2; ++i)
				++d2[comp[i]-'0'];
			bool same = true;
			for (int i=1; i<=9; ++i)
				if (d[i] != d2[i])
					same = false;
			if (same)
				break;
		}*/
		if (!next_permutation(n, n + l)) {
			for (int i=l; i>0; --i)
				n[i] = n[i-1];
			n[0] = '0';
			int i = 1;
			while(n[i] == '0')
				++i;
			swap(n[i], n[0]);
			n[l+1] = 0;
		}
		assert(n[0] != '0');
/*		if (strcmp(comp, n)) {
			puts(comp);
			puts(n);
			exit(1);
		}*/
		puts(n);
	}
	return 0;
}
