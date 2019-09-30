#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
using namespace std;

#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)

int T;
vector<int> adj[500];
bool ad[500][500];
int dist[500];
int dp[500][500];

int main() {
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		int P, W;
		scanf("%d %d", &P, &W);
		for (int i = 0; i < P; i++) {
			adj[i].clear();
		}
		for (int i = 0; i <= P; i++) {
			dist[i] = 1E9;
			for (int k = 0; k <= P; k++) {
				dp[i][k] = -1E9;
				ad[i][k] = false;
			}
		}
		for (int i = 0; i < W; i++) {
			int a, b;
			scanf("%d,%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
			ad[a][b] = ad[b][a] = true;
		}
		queue<int> qu;
		qu.push(0);
		dist[0] = 0;
		dp[0][P] = 0;
		for (int k = 0; k < P; k++)
			if (ad[0][k])
				dp[0][P]++;
		while(!qu.empty()) {
			int i = qu.front();
			qu.pop();
			FOREACH(ik,adj[i]) {
				int k = *ik;
				if (dist[k] == 1E9) {
					dist[k] = dist[i]+1;
					qu.push(k);
				} else if (dist[k] == dist[i]-1) {
					for (int r = 0; r <= P; r++) {
						if (dp[k][r] < 0)
							continue;
						int d = dp[k][r]-1;
						for (int s = 0; s < P; s++) {
							if (ad[i][s] && !ad[k][s] && !ad[r][s] && s != k && s != r)
								d++;
						}
						dp[i][k] = max(dp[i][k], d);
					}
				}
			}
		}
		
		int mindist = 1E9+1, maxan = -1E9;
		FOREACH(ik, adj[1]) {
			int k = *ik;
			if (dist[k] > mindist)
				continue;
			for (int r = 0; r <= P; r++) {
				if (dist[k] < mindist || (dist[k] == mindist && dp[k][r] > maxan)) {
					mindist = dist[k];
					maxan = dp[k][r];
				}
			}
		}
		printf("%d %d\n", mindist, maxan);
		
		/*for (int k = 0; k <= P; k++)
			printf("%d ", k);
		printf("\n");
		for (int i = 0; i < P; i++) {
			for (int k = 0; k <= P; k++) {
				if (dp[i][k] != -1E9)
					printf("%d ", dp[i][k]);
				else
					printf("  ");
			}
			printf("\n");
		}*/
	}
	return 0;
}
