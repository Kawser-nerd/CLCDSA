#include <cstdio>
#include <string>
#include <map>
using namespace std;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)

char buf[110];
const int inf = 1000000000;

int main() {
	int zzz;
	gets(buf);
	sscanf(buf, "%d", &zzz);
	REP(zz,zzz) {
		map<string,int> num;
		int s;
		gets(buf);
		sscanf(buf, "%d", &s);
		REP(i,s) {
			gets(buf);
			num[buf] = i;
		}
		int q;
		gets(buf);
		sscanf(buf, "%d", &q);
		int res[100], mil[100], mir[100];
		REP(i,s)
			res[i] = 0;
		REP(i,q) {
			gets(buf);
			int k = num[buf];
			mil[0] = inf;
			REP(j,s-1)
				mil[j+1] = mil[j] <? res[j];
			mir[s-1] = inf;
			REPD(j,s-1)
				mir[j] = mir[j+1] <? res[j+1];
			REP(j,s)
				if (j == k)
					res[j] = inf;
				else
					res[j] <?= (mil[j] <? mir[j]) + 1;
		}
		int r = inf;
		REP(i,s)
			r <?= res[i];
		printf("Case #%d: %d\n", zz+1, r);
	}
}
