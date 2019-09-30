#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("B-large.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("B-large.out", "w", stdout);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		int stuff[n];
		for(int i = 0; i < n; i++) cin >> stuff[i];
		int answer = 1000;
		for(int i = 1; i <= 1000; i++){
			int cur = i;
			for(int j = 0; j < n; j++){
				cur += (stuff[j]-1)/i;
			}
			answer = min(answer, cur);
		}
		cout << answer << endl;
	}
	exit(0);
}