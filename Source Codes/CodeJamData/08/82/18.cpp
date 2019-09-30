#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

typedef pair <int, int> PII;
typedef long long llong;
typedef vector <int> VI;
typedef vector <string> VS;

#define MP make_pair
#define PB push_back
#define x first
#define y second
#define FORI(p, X) for(__typeof((X).begin()) p = (X).begin(); p != (X).end(); ++p)
#define ALL(X) (X).begin(), (X).end()

const int INF = 0x3f3f3f3f;
const int NMAX = 303;

int get(vector <PII> &A, int &i, int l) {
	int r = -1;

	for (; i < (int) A.size() && A[i].x <= l; ++i)
		r = max(A[i].y, r);
	
	return r;
}

int main(void) {
	freopen("large.in", "rt", stdin);
	freopen("test.out", "wt", stdout);

	int cn, CN;
	int i, j, k, ii, ij, ik, a, b, l, st, dr, r, c, v;
	map <string, int> M;
	vector <PII> T[NMAX];
	string col;
	int N, NC, R;

	cin >> CN;

	for (cn = 1; cn <= CN; ++cn) {

		cin >> N;

		NC = 0; R = INF;
		for (i = 0; i < N; ++i) {
			cin >> col >> st >> dr;

			if (M.find(col) == M.end())
				M[col] = NC++;
			v = M[col];

			T[v].PB(MP(st, dr));
		}

		for (i = 0; i < NC; ++i)
			sort(ALL(T[i]));

		for (i = 0; i < NC; ++i)
			for (j = i; j < NC; ++j)
				for (k = j; k < NC; ++k) {
					r = 0;
					l = 1;
					ii = ij = ik = 0;

					while (l < 10001) {
						a = get(T[i], ii, l);
						b = get(T[j], ij, l);
						c = get(T[k], ik, l);

						if (a == -1 && b == -1 && c == -1) break;
						if (a >= l) l = a + 1;
						if (b >= l) l = b + 1;
						if (c >= l) l = c + 1;
						++r;
					}

//					printf("%d\n", l);
					if (l == 10001)
						R = min(r, R);


				}
	
		M.clear();
		for (i = 0; i < NC; ++i)
			T[i].clear();

		printf("Case #%d: ", cn);
		if (R == INF) printf("IMPOSSIBLE\n");
		else printf("%d\n", R);
	}

	return 0;
}
