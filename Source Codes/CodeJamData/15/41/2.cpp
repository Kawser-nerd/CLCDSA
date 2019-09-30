#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

string ds = "^v><";
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int X,Y;
string board[110];
int a[110][110];

bool check(int x, int y, int d){
	int i;
	for(i=1;;i++){
		int x2 = x + i * dx[d], y2 = y + i * dy[d];
		if(!(x2 >= 0 && x2 < X && y2 >= 0 && y2 < Y)) return false;
		if(a[x2][y2] != -1) return true;
	}
}

void main2(void){
	int i,j,k;
	
	cin >> X >> Y;
	REP(i,X) cin >> board[i];
	REP(i,X) REP(j,Y){
		a[i][j] = -1;
		REP(k,4) if(board[i][j] == ds[k]) a[i][j] = k;
	}
	
	int ans = 0;
	REP(i,X) REP(j,Y) if(a[i][j] != -1){
		int tmp = 2;
		REP(k,4) if(check(i, j, k)) tmp = 1;
		if(check(i, j, a[i][j])) tmp = 0;
		if(tmp == 2){
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		ans += tmp;
	}
	
	cout << ans << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
