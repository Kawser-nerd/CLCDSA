#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
typedef vector<int> VI;

int t;

int stime() {
	int h, m;
	scanf("%d:%d", &h, &m);
	return 60 * h + m;
}

int reduce(VI& arr, VI& dep) {
	sort(ALL(arr));
	sort(ALL(dep));
	int n = arr.size(), m = dep.size();
	vector<bool> used(n);
	int res = 0;
	REPD(j,m) {
		REPD(i,n)
			if (!used[i] && arr[i] + t <= dep[j]) {
				res++;
				used[i] = true;
				break;
			}
	}
	return res;
}

int main() {
	int zzz;
	scanf("%d", &zzz);
	REP(zz,zzz) {
		int na, nb;
		scanf("%d%d%d", &t, &na, &nb);
		VI depa, depb, arra, arrb;
		REP(i,na) {
			depa.PB(stime());
			arrb.PB(stime());
		}
		REP(i,nb) {
			depb.PB(stime());
			arra.PB(stime());
		}
		printf("Case #%d: %d %d\n", zz+1, na - reduce(arra, depa), nb - reduce(arrb, depb));
	}
}
