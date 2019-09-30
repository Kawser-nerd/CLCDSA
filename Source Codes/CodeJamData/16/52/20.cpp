#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

using namespace std;
typedef long long LL;
typedef function<int(int)> VALF;

#define pb push_back
#define mt make_tuple
#define SZ(V) ((int)((V).size()))

const int MAX_N = 1024;
const int MAX_M = 1024;
const int MAX_M_LEN = 1024;
int pr[MAX_N], deg[MAX_N], cdeg[MAX_N];
char ch[MAX_N], cool[MAX_M][MAX_M_LEN];
int N, M;

int cand[MAX_N], cc;
char word[MAX_N];

int sexist[MAX_M];
int scount;

double entropy[MAX_N];
double Comb[MAX_N][MAX_N];

int cnt[MAX_N];

vector<int> clist[MAX_N];

void preprocess() {
	cc = 0;
	for (int i = 0; i < N; i++) {
		cnt[i] = 0;
		if (deg[i] == 0) {
			cnt[i] ++;
			cand[cc++] = i;
		}
		cdeg[i] = 0;
		entropy[i] = 1.0;
	}
	for (int i = 0; i < cc; i++) {
		int v = cand[i];
		if (pr[v] >= 0) {
			int p = pr[v];
			clist[p].push_back(v);

			entropy[p] *= entropy[v];
			int bcnt = cnt[p];
			int ncnt = bcnt + cnt[v];
			entropy[p] *= Comb[ncnt][bcnt];

			cnt[p] = ncnt;

			cdeg[p] ++;
			if (cdeg[p] == deg[p]) {
				cnt[p] ++;
				cand[cc++] = p;
			}
		}
	}
}

const int RD30 = (1 << 30);
int rand30() {
	return (rand() << 15) + (rand());
}

double cprob[MAX_N];
void insertCand(int a) {
	cand[cc] = a;
	/*
	double emult = 1.0;
	for (auto c : clist[a]) {
		emult *= entropy[c];
	}
	cprob[cc] = emult / entropy[a];
	*/
	cc++;
}

void Sample() {
	cc = 0;
	for (int i = 0; i < N; i++) {
		if (pr[i] >= 0) {
		}
		else {
			insertCand(i);
		}
	}
	int remain = N;
	for (int i = 0; i < N; i++) {
		double all = 0.0;
		for (int j = 0; j < cc; j++) {
			int u = cand[j];
			int cu = cnt[u];
			cprob[j] = Comb[remain-1][cu-1] / Comb[remain][cu];
		}
		for (int j = 0; j < cc; j++) {
			all += cprob[j];
		}
		double rd30 = (rand30() / (double)RD30) * all;
		all = 0;
		int pick = cc - 1;
		for (int j = 0; j < cc; j++) {
			all += cprob[j];
			if (all >= rd30) {
				pick = j;
				break;
			}
		}
		
		int v = cand[pick];
		cand[pick] = cand[cc - 1];
		cc--;

		word[i] = ch[v];
		for (auto c : clist[v]) {
			insertCand(c);
		}
		remain--;
	}
	word[N] = '\0';
	string S = word;
	for (int i = 0; i < M; i++) {
		if (S.find(cool[i]) != string::npos) {
			sexist[i] ++;
		}
	}
}

int main() {
	srand(0x10101);
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	Comb[0][0] = 1.0;
	for (int i = 1; i < MAX_N; i++) {
		Comb[i][0] = 1.0;
		for (int j = 1; j < MAX_N; j++) {
			Comb[i][j] = Comb[i - 1][j] + Comb[i - 1][j - 1];
		}
	}
	for (int tc = 1; tc <= T; tc++) {
		fprintf(stderr, "%d\n", tc);
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			deg[i] = 0;
			cdeg[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &pr[i]);
			pr[i] --;
			if (pr[i] >= 0) {
				deg[pr[i]] ++;
			}
		}
		scanf("%s", ch);
		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			scanf("%s", cool[i]);
			sexist[i] = 0;
		}
		preprocess();
		scount = 0;
		for (int i = 0; i < 20000; i++) {
			Sample();
			scount++;
		}

		printf("Case #%d: ", tc);
		for (int i = 0; i < M; i++) {
			printf("%.2lf ", ((double)sexist[i]) / (double)scount);
		}
		printf("\n");
		for (int i = 0; i < N; i++) clist[i].clear();
	}
	return 0;
}