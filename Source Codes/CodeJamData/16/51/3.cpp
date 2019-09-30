#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

char stuff[21000];
main() {
	FILE *fin = freopen("A-large.in", "r", stdin);
	FILE *fout = freopen("A-large.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		scanf("%s", stuff);
		int n = strlen(stuff);
		vector<char> d;
		int ans = 5*n/2;
		for(int i = 0; i < n; i++){
			if(d.size() > 0 && d[d.size()-1] == stuff[i]){
				d.pop_back();
				ans += 5;
			} else {
				d.push_back(stuff[i]);
			}
		}
		printf("%d\n", ans);
	}
	exit(0);
}