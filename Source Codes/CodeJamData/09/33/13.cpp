#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m;
int q[100000];
long long d[1000][1000];

int main(void) {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int i, j, k, x, t;

	scanf("%d", &t);
	for(x = 0; x < t; x++) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < m; i++)
			scanf("%d", &q[i]);
		q[m++] = 0;
		q[m++] = n + 1;

		sort(q, q+m);

		for(j = 0; j < m; j++) 
			for(i = j - 2; i >= 0; i--) {
				d[i][j] = -1;
				for(k = i + 1; k < j; k++)
					if (d[i][j] == -1 || d[i][j] > d[i][k] + d[k][j] + q[j] - q[i] - 2)
						d[i][j] = d[i][k] + d[k][j] + q[j] - q[i] - 2;
			}
			
		
		long long sol = d[0][m-1];

		cout << "Case #" << x+1 << ": " << sol << endl;
	}

	exit(0);
}