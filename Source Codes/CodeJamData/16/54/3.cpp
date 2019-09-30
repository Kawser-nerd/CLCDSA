#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("D-large.in", "r", stdin);
	FILE *fout = freopen("D-large.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		int n, l;
		cin >> n >> l;
		string c[n];
		string bad;
		for(int i = 0; i < n; i++){
			cin >> c[i];
		}
		cin >> bad;
		int fail = 0;
		for(int i = 0; i < n; i++){
			if(bad == c[i]){
				fail = 1;
				break;
			}
		}
		if(fail){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		for(int i = 0; i < l; i++){
			cout << char('0'+'1'-bad[i]) << "?";
		}
		cout << " ";
		for(int i = 0; i < l; i++){
			if(i > 0) cout << bad[i];
			cout << char('0'+'1'-bad[i]);
		}
		cout << endl;
	}
	exit(0);
}