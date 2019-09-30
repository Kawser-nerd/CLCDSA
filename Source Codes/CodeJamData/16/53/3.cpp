#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("C-sample.in", "r", stdin);
	FILE *fout = freopen("C-sample.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		int n, s;
		cin >> n >> s;
		double x[3][n];
		double v[3][n];
		for(int i = 0; i < n; i++){
			cin >> x[0][i] >> x[1][i] >> x[2][i];
			cin >> v[0][i] >> v[1][i] >> v[2][i];
		}
		double dist[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				double r = 0;
				for(int z = 0; z < 3; z++){
					r += (x[z][i]-x[z][j])*(x[z][i]-x[z][j]);
				}
				dist[i][j] = sqrt(r);
			}
			dist[i][i] = 0.0;
		}
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		printf("%.10lf\n", dist[0][1]);
	}
	exit(0);
}