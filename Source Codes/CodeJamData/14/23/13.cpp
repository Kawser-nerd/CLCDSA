#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,a,n) for (int i = (a); i < (n); i++)

int T;

int N, M;
int code[100];
bool m[100][100];
vector<bool> vis, vis2;
vector<bool> done;
vector<int> st;

void visit(int i) {
	if (vis2[i] || done[i])
		return;
	vis2[i] = true;
	REP(j,0,N)
		if (m[i][j])
			visit(j);
}

bool ok(int k) {
	while(!st.empty() && !m[st.back()][k]) {
		done[st.back()] = true;
		st.pop_back();
	}
	if (st.empty())
		return false;
	vis[k] = true;
	st.push_back(k);
	vis2.assign(N, false);
	visit(st[0]);
	REP(i,0,N)
		if (!done[i] && !vis2[i])
			return false;
	return true;
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d%d", &N, &M);
		REP(i,0,N) REP(j,0,N)
			m[i][j] = false;
		REP(i,0,N)
			scanf("%d", &code[i]);
		REP(i,0,M) {
			int a, b;
			scanf("%d%d", &a, &b);
			a--; b--;
			m[a][b] = m[b][a] = true;
		}
		vis.assign(N, false);
		done.assign(N, false);
		st.clear();
		int mi = 0;
		REP(i,0,N)
			if (code[mi] > code[i])
				mi = i;
		st.push_back(mi);
		vis[mi] = true;
		printf("%d", code[mi]);
		REP(r,1,N) {
			VPII cand;
			REP(i,0,N)
				if (!vis[i])
					cand.push_back(PII(code[i], i));
			sort(cand.begin(), cand.end());
			bool fo = false;
			FOREACH(it, cand) {
				vector<bool> viss = vis, donee = done;
				vector<int> stt = st;
				if (ok(it->second)) {
					printf("%d", code[it->second]);
					fo = true;
					break;
				}
				vis = viss;
				done = donee;
				st = stt;
			}
			assert(fo);
		}
		printf("\n");
	}
	return 0;
}
