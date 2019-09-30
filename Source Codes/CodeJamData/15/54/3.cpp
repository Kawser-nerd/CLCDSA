#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

#include <math.h>
#include <stdio.h>
long long P;
long long E[10001], F[10001];
vector<pair<long long, long long> > EF;
long long Qe[10001], Qf[10001], head;
bool poscheck(long long v) {
	vector<pair<long long, long long> > cEF = EF, nEF;
	long long tail = 0;
	head = 0;
	bool found = false;
	for (int i = 0; i < (int)cEF.size(); i++) {
		if (cEF[i].first == v) {
			found = true;
		}
	}
	if (!found) return false;
	if (v < 0) {
		for (int i = 0; i < (int)cEF.size(); i++) {
			long long e = cEF[i].first;
			long long f = cEF[i].second;
			if (tail < head) {
				if (Qe[tail] == e) {
					f -= Qf[tail];
					tail++;
				}
			}

			if (f > 0) {
				Qe[head] = e - v;
				Qf[head] = f;
				head++;
				nEF.push_back(make_pair(e - v, f));
			}
			else if (f < 0) {
				return false;
			}
		}
	}
	else if (v == 0) {
		for (int i = 0; i < (int)cEF.size(); i++) {
			long long e = cEF[i].first;
			long long f = cEF[i].second;
			if (f % 2 != 0) return false;
			nEF.push_back(make_pair(e, f / 2));
		}
	}
	else {
		for (int i = (int)cEF.size() - 1; i >= 0; i--) {
			long long e = cEF[i].first;
			long long f = cEF[i].second;
			if (tail < head) {
				if (Qe[tail] == e) {
					f -= Qf[tail];
					tail++;
				}
			}

			if (f > 0) {
				Qe[head] = e - v;
				Qf[head] = f;
				head++;
				nEF.push_back(make_pair(e - v, f));
			}
			else if (f < 0) {
				return false;
			}
		}
		reverse(nEF.begin(), nEF.end());
	}
	if (tail != head) return false;
	EF = nEF;
	return true;
}
int main(){
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		fprintf(stderr, "%d\n", cs);
		scanf("%lld", &P);
		for (long long i = 0; i < P; i++) {
			scanf("%lld", &E[i]);
		}
		for (long long i = 0; i < P; i++) {
			scanf("%lld", &F[i]);
		}
		EF.clear();
		for (long long i = 0; i < P; i++) {
			EF.push_back(make_pair(E[i], F[i]));
		}
		sort(EF.begin(), EF.end());
		printf("Case #%d: ", cs);
		for (long long i = 0; i < P; i++) {
			if (poscheck(E[i]))
			{
				printf("%lld ", E[i]);
				i--;
				continue;
			}
		}
		if (EF.size() > 1 || EF[0].second > 1) fprintf(stderr, "FAIL");
		printf("\n");
	}

	return 0;
}