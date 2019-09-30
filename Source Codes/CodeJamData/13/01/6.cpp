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

bool win(string s, char c) {
	for(int i = 0; i < s.size(); i++) {
		if( s[i] != c && s[i] != 'T' ) return false;
	}
	return true;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for(cases = 1; cases <= test; cases++) {
		string grid[10];
		for(int i = 0; i < 4; i++)
			cin >> grid[i];

		int state = 0;
		for(int i = 0; i < 4; i++) {
			if( win(grid[i], 'X') ) state = 1;
			if( win(grid[i], 'O') ) state = 2;
		}
		for(int i = 0; i < 4; i++) {
			string s = "";
			for(int j = 0; j < 4; j++)
				s += grid[j][i];
			if( win(s, 'X') ) state = 1;
			if( win(s, 'O') ) state = 2;
		}

		string s = "";
		for(int i = 0; i < 4; i++) s += grid[i][i];
		if( win(s, 'X') ) state = 1;
		if( win(s, 'O') ) state = 2;

		s = "";
		for(int i = 0; i < 4; i++) s += grid[3-i][i];
		if( win(s, 'X') ) state = 1;
		if( win(s, 'O') ) state = 2;

		if( state == 1 || state == 2 ) {
			printf("Case #%d: %s won\n", cases, state == 1 ? "X" : "O");
			continue;
		}
		bool dot = false;
		for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) if( grid[i][j] == '.') dot = true;
		if( dot == true)
			printf("Case #%d: Game has not completed\n", cases);
		else
			printf("Case #%d: Draw\n", cases);
	}
	return 0;
}
