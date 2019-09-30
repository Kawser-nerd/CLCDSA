#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

#include <math.h>
#include <stdio.h>
const int MAX_N = 1000001;
int N, D;

int S0, As, Cs, Rs;
int M0, Am, Cm, Rm;

int S[MAX_N];
int M[MAX_N];

vector<int> childs[MAX_N];
const int max_salary = 1000000;
vector<int> stable[max_salary + 1];

bool used[MAX_N];
int use_cnt, sol;
int rs, re;
void append(int a) {
	if (a != 0) {
		int p = M[a];
		if (!used[p]) return;
	}
	if (used[a]) return;
	if (rs <= S[a] && S[a] <= re) {
		used[a] = true;
		use_cnt++;
		for (int b : childs[a]) {
			append(b);
		}
	}
}

void cut(int a) {
	if (!used[a]) return;

	used[a] = false;
	use_cnt--;

	for (int b : childs[a]) {
		cut(b);
	}
}

void proc() {
	sol = 0;
	for (int i = 0; i < N; i++) {
		stable[S[i]].push_back(i);
	}

	memset(used, 0, sizeof(used));
	use_cnt = 0;
	rs = S[0] - D;
	re = S[0];

	append(0);
	while (rs <= S[0]) {
		if (use_cnt > sol) sol = use_cnt;
		if (rs >= 0) {
			for (int x : stable[rs]) {
				cut(x);
			}
		}
		rs++; re++;
		if (re <= max_salary) {
			for (int x : stable[re]) {
				append(x);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		stable[S[i]].clear();
	}
}
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		scanf("%d %d", &N, &D);
		scanf("%d %d %d %d", &S0, &As, &Cs, &Rs);
		scanf("%d %d %d %d", &M0, &Am, &Cm, &Rm);
		S[0] = S0;
		M[0] = M0;
		for (int i = 0; i < N-1; i++) {
			S[i + 1] = (S[i] * As + Cs) % Rs;
			M[i + 1] = (M[i] * Am + Cm) % Rm;
		}
		for (int i = 1; i < N; i++) {
			M[i] %= i;
			childs[M[i]].push_back(i);
		}

		proc();
		printf("Case #%d: %d\n", cs, sol);

		for (int i = 0; i < N; i++) childs[i].clear();
	}

	return 0;
}