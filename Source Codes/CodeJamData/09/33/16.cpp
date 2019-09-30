#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int P, Q;
int id[100];
int r[100][100];

void read_data()
{
	scanf("%d%d", &P, &Q);
	for (int i = 0; i < Q; ++i)
		scanf("%d", &id[i]);
}

void solve()
{
	memset(r, 0, sizeof(r));
	for (int l = 1; l <= Q; ++l)
		for (int i = 0; i+l <= Q; ++i) {
			int l_id, r_id;
			if (i == 0) l_id = 1; else l_id = id[i-1] + 1;
			if (i+l == Q) r_id = P; else r_id = id[i+l] - 1;

			r[i][i+l-1] = 1000000000;
			for (int k = i; k < i+l; ++k) {
				int cost = r_id - l_id;
				if (k > i) cost += r[i][k-1];
				if (k < i+l-1) cost += r[k+1][i+l-1];
				if (r[i][i+l-1] > cost) r[i][i+l-1] = cost;
			}
		}

	printf("%d\n", r[0][Q-1]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		read_data();
		solve();
	}

	return 0;
}
