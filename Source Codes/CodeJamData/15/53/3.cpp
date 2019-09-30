/*
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

#include <math.h>
#include <stdio.h>

const int MAX_N = 501;
double dyn[MAX_N][MAX_N][MAX_N];
bool dyc[MAX_N][MAX_N][MAX_N];

int N;
double Y;

int P[MAX_N];
double S[MAX_N];

vector< pair<double, int> > lv, rv;
void updateDyn(int a, int b, int c, double d) {
	double &D = dyn[a][b][c];
	if (!dyc[a][b][c]) {
		dyc[a][b][c] = true;
		D = d;
	}
	else {
		if (D > d) D = d;
	}
}
double getDist(double pos, double gpos, double run) {
	double mm = Y - run;
	double dif = (gpos - pos);
	if (dif < 0) dif = -dif;
	return dif / mm;
}
double getPos(int i, double t) {
	double v = S[i];
	if (P[i] < 0) v = -v;
	return (double)P[i] + (v * t);
}

double sol = 0.0f;
bool solc = false;
int mark[26];
int last_mark[26];
void back(double p, double t, int dep) {
	int li, ri;
	li = -1; ri = -1;
	double ld, rd;
	ld = rd = 0.0;
	for (int i = 0; i < N; i++){
		if (!mark[i]) {
			double pi = getPos(i, t);
			double d = getDist(p, pi, S[i]);
			if (pi > 0) {
				if (ri == -1 || rd > d) {
					ri = i;
					rd = d;
				}
			}
			else {
				if (li == -1 || ld > d) {
					li = i;
					ld = d;
				}
			}
		}
	}
	if (li != -1) {
		mark[li] = dep;
		back(getPos(li, t + ld), t + ld, dep+1);
		mark[li] = 0;
	}
	if (ri != -1) {
		mark[ri] = dep;
		back(getPos(ri, t + rd), t + rd, dep+1);
		mark[ri] = 0;
	}

	if (li == -1 && ri == -1) {
		if (!solc || sol > t) {
			sol = t;
			solc = true;
			for (int i = 0; i < N; i++) last_mark[i] = mark[i];
		}
	}
}
void proc() {
	solc = false;
	back(0.0, 0.0, 1);
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		memset(dyc, 0, sizeof(dyc));
		scanf("%lf %d", &Y, &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%lf", &S[i]);
		}
		lv.clear();
		rv.clear();
		for (int i = 0; i < N; i++) {
			if (P[i] < 0) {
				lv.push_back(make_pair(S[i], i));
			}
			else {
				rv.push_back(make_pair(S[i], i));
			}
		}
		sort(lv.begin(), lv.end());
		reverse(lv.begin(), lv.end());
		sort(rv.begin(), rv.end());
		reverse(rv.begin(), rv.end());

		proc();

		printf("Case #%d: %.9lf\n", cs, sol);
		//for (int i = 0; i < N; i++) printf("%d ", last_mark[i]);
		//printf("\n");
	}

	return 0;
}
*/
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

#include <math.h>
#include <stdio.h>

const int MAX_N = 501;
double dyn[MAX_N][MAX_N][MAX_N];
bool dyc[MAX_N][MAX_N][MAX_N];

int N;
double Y;

int P[MAX_N];
double S[MAX_N];

vector< pair<double, int> > lv, rv;
void updateDyn(int a, int b, int c, double d) {
	double &D = dyn[a][b][c];
	if (!dyc[a][b][c]) {
		dyc[a][b][c] = true;
		D = d;
	}
	else {
		if (D > d) D = d;
	}
}
double getDist(double pos, double gpos, double run) {
	double mm = Y - run;
	double dif = (gpos - pos);
	if (dif < 0) dif = -dif;
	return dif / mm;
}
double getPos(int i, double t) {
	double v = S[i];
	if (P[i] < 0) v = -v;
	return (double)P[i] + (v * t);
}

double sol = 0.0f;
void proc() {
	if (lv.size() > 0) {
		int i = lv[0].second;
		updateDyn(1, 0, i, getDist(0.0, (double)P[i], S[i]));
	}
	if (rv.size() > 0) {
		int i = rv[0].second;
		updateDyn(0, 1, i, getDist(0.0, (double)P[i], S[i]));
	}

	bool solc = false;
	for (int a = 0; a <= (int)lv.size(); a++) {
		if (a == lv.size()) {
			a = a;
		}
		for (int b = 0; b <= (int)rv.size(); b++) {
			for (int c = 0; c < N; c++) {
				if (!dyc[a][b][c]) continue;
				if (a < (int)lv.size()) {
					if (dyc[a + 1][b][c]) {
						if (dyn[a + 1][b][c] <= dyn[a][b][c]) continue;
					}
				}
				if (b < (int)rv.size()) {
					if (dyc[a][b + 1][c]) {
						if (dyn[a][b + 1][c] <= dyn[a][b][c]) continue;
					}

				}

				double nowT = dyn[a][b][c];
				double nowP = getPos(c, nowT);

				if (a < (int)lv.size()) {
					int li = lv[a].second;
					double pl = getPos(li, nowT);

					for (int ta = a; ta < (int)lv.size(); ta++) {
						int tli = lv[ta].second;
						double tpl = getPos(tli, nowT);
						if (nowP <= tpl) {
							updateDyn(ta + 1, b, c, nowT);
						}
						else {
							break;
						}
					}

					double d = getDist(nowP, pl, S[li]);
					updateDyn(a + 1, b, li, nowT + d);
				}
				if (b < (int)rv.size()) {
					int ri = rv[b].second;
					double pr = getPos(ri, nowT);

					for (int tb = b; tb < (int)rv.size(); tb++) {
						int tri = rv[tb].second;
						double tpr = getPos(tri, nowT);
						if (nowP >= tpr) {
							updateDyn(a, tb + 1, c, nowT);
						}
						else {
							break;
						}
					}

					double d = getDist(nowP, pr, S[ri]);
					updateDyn(a, b + 1, ri, nowT + d);
				}

				if (a == (int)lv.size() && b == (int)rv.size()) {
					if (!solc) {
						sol = nowT;
						solc = true;
					}
					else {
						if (sol > nowT) sol = nowT;
					}
				}
			}
		}
	}
}
int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		memset(dyc, 0, sizeof(dyc));
		scanf("%lf %d", &Y, &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%lf", &S[i]);
		}
		lv.clear();
		rv.clear();
		for (int i = 0; i < N; i++) {
			if (P[i] < 0) {
				lv.push_back(make_pair(S[i], i));
			}
			else {
				rv.push_back(make_pair(S[i], i));
			}
		}
		sort(lv.begin(), lv.end());
		reverse(lv.begin(), lv.end());
		sort(rv.begin(), rv.end());
		reverse(rv.begin(), rv.end());

		proc();

		printf("Case #%d: %.9lf\n", cs, sol);
	}

	return 0;
}

