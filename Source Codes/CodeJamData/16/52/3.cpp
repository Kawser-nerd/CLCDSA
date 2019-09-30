#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("B-small-attempt1.in", "r", stdin);
	FILE *fout = freopen("B-small-attempt1.out2", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ":";
		int n;
		cin >> n;
		int par[n+1];
		for(int i = 1; i <= n; i++){
			cin >> par[i];
		}
		par[0] = 0;
		string c;
		cin >> c;

		int m;
		cin >> m;

		string q[m];
		int num[m];
		for(int i = 0; i < m; i++){
			cin >> q[i];
			num[i] = 0;
		}

		int vis[n+1];
		int rr = 10000;
		for(int v = 0; v < rr; v++){
			int z = 0;
			for(int i = 0; i <= n; i++) vis[i] = 0;
			vis[0] = 1;
			string d;
			while(z < n){
				int cur = rand() % n + 1;
				if(!vis[cur]){
					while(!vis[par[cur]]){
						cur = par[cur];
					}
					vis[cur] = 1;
					d += c[cur-1];
					z++;
				}
			}
			//cout << d << endl;
			for(int i = 0; i < m; i++){
				if (d.find(q[i]) != string::npos) {
					num[i]++;
				}
			}
		}
		for(int i = 0; i < m; i++){
			double p = (double)num[i] / (double) rr;
			cout << " " << p;
		}
		cout << endl;
	}
	exit(0);
}