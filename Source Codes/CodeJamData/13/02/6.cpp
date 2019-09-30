#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

// ------------- PRE-WRITTEN CODES ---------------------------------

// defines and const
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

// input reading
template<class T>
vector<T> takeInput(int n) {
	vector<T> list;
	T a; int i;
	for(i = 0; i < n; i++) { cin >> a; list.push_back(a); }
	return list;
}

// math
long long ncr[305][305] = {0};
void gen_ncr(int n) {
	int i, j;
	for(i = 0; i <= n; i++) ncr[i][0] = 1;
	for(i=1; i<=n; i++) for(j=1;j<=n;j++)  ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
}

double dis(double x1, double y1, double x2, double y2) {
	return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

// --------------- END of PRE-WRITTEN CODES --------------------------

int main() {
	int test, cases = 1;
	cin >> test;
	for(cases = 1; cases <= test; cases++) {
		int grid[105][105];
		int result[105][105];
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				cin >> grid[i][j];
				result[i][j] = 100;
			}

		for(int i = 0; i < n; i++) {
			int maxv = -1;
			for(int j = 0; j < m ;j++)
				maxv >?= grid[i][j];
			for(int j = 0; j < m; j++)
				result[i][j] <?= maxv;
		}

		for(int j = 0; j < m; j++) {
			int maxv = -1;
			for(int i = 0; i < n; i++)
				maxv >?= grid[i][j];
			for(int i = 0; i < n; i++)
				result[i][j] <?= maxv;
		}
		bool yes = true;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if( grid[i][j] != result[i][j] ) yes = false;

		printf("Case #%d: %s\n", cases, yes ? "YES" : "NO");



	}
	return 0;
}
