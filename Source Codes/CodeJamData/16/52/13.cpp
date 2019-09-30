#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <random>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
int N, M, P[100];
char C[105];
char cool[5][25];

double ans[5];

vector<int> graph[105];
vector<int> root;
int n_ch[105];

mt19937 rnd;
const int Tr = 3000;
char S[Tr][105];
void test(int ti)
{
	root.clear();
	for (int i = 0; i < N; ++i) {
		if (P[i] == -1) {
			root.push_back(i);
	//		printf("a%d\n", i);
		}
	}
	for (int i = 0; i < N; ++i) {
	//	printf("%d\n", root.size());
		vector<int> ds;
		for (int j : root) ds.push_back(n_ch[j]);
		discrete_distribution<int> dist(ds.begin(), ds.end());

		int idx = dist(rnd);
		if (idx != root.size() - 1) swap(root[idx], root[root.size() - 1]);
		int p = root[root.size() - 1];
		root.pop_back();
		S[ti][i] = C[p];
		for (int q : graph[p]) root.push_back(q);
	}
}

double freq[100][26];

bool is_match(char* a, char* b)
{
	int L = strlen(b);
	for (int i = 0; i <= N - L; ++i) {
		for (int j = 0; j < L; ++j) if (a[i + j] != b[j]) goto nex;
		return true;
	nex:
		continue;
	}
	return false;
}

int dfs(int p)
{
	if (n_ch[p] == -1) {
		n_ch[p] = 1;
		for (int q : graph[p]) n_ch[p] += dfs(q);
	}
	return n_ch[p];
}

int main()
{
	random_device dev;
	rnd = mt19937(dev());

	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", P + i);
			--P[i];
		}
		scanf("%s", C);
		scanf("%d", &M);
		for (int i = 0; i < M; ++i) scanf("%s", &(cool[i]));

		for (int i = 0; i < N; ++i) graph[i].clear();
		for (int i = 0; i < N; ++i) {
			if (P[i] >= 0) graph[P[i]].push_back(i);
			n_ch[i] = -1;
		}
		for (int i = 0; i < N; ++i) n_ch[i] = dfs(i);
		//for (int i = 0; i < N; ++i) printf("%d\n", graph[i].size());
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 26; ++j) freq[i][j] = 0;
		}
		for (int r = 0; r < Tr; ++r) {
			test(r);
			for (int i = 0; i < N; ++i) freq[i][S[r][i] - 'A'] += 1.0;
			S[r][N] = 0;
		//	puts(S[r]);
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 26; ++j) freq[i][j] /= Tr;
		}
		double p_ok[5], p_ng[5];
		for (int i = 0; i < M; ++i) p_ok[i] = p_ng[i] = 0.0;

		for (int i = 0; i < Tr; ++i) {
			double prob = 1.0;
			//for (int j = 0; j < N; ++j) prob *= freq[j][S[i][j] - 'A'];

			for (int j = 0; j < M; ++j) {
				bool f = is_match(S[i], cool[j]);
				if (f) p_ok[j] += prob;
				else p_ng[j] += prob;
			}
		}

		for (int i = 0; i < M; ++i) ans[i] = p_ok[i] / (p_ok[i] + p_ng[i]);
		printf("Case #%d:", t);
		for (int i = 0; i < M; ++i) printf(" %f", ans[i]);
		puts("");
	}

	return 0;
}
