#include <iostream> 
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_N 50
#define MAX_M 50

int main() {
	int n,m;
	cin >> n >> m;
	int out[MAX_N] = {0};
	// int road[MAX_M][2];
	for (int i(0); i < m ; i++) {
		int a,b;
		cin >> a >> b;
		out[a - 1] += 1;
		out[b - 1] += 1;
		// cin >> road[i][0] >> road[i][1];
		// out[road[i][0] - 1] += 1;
		// out[road[i][1] - 1] += 1;
	}
	for (int i(0);i < n; i++){
		cout << out[i] << endl;
	}

	// for (int i(0); i < m ; i++) {
		// cout << road[i][0] << road[i][1];
	// }
	// string a,b,c;
	// cin >> a >> b >> c;
	// if (a[a.length() - 1] == b[0]) {
		// if (b[b.length() - 1] == c[0]) {
			// cout << "YES";
			// return 0;
		// }
	// }
	// cout << "NO";
    return 0;
 }