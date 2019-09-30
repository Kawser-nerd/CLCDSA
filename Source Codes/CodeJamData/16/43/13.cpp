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

int input[1000];

int H,W;
char board[20][20];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int func(int x, int y, int d){
	if(x >= 0 && x < H && y >= 0 && y < W){
		if(board[x][y] == '/') d ^= 1; else d ^= 3;
		return func(x + dx[d], y + dy[d], d);
	}
	
	if(x < 0) return y;
	if(y >= W) return W + x;
	if(x >= H) return W + H + (W - 1 - y);
	return W + H + W + (H - 1 - x);
}

bool check(void){
	int i;
	
	int N = 2 * (H + W);
	
	for(i=0;i<N;i+=2){
		int id = input[i];
		
		int goal = -1;
		if(id < W){
			goal = func(0, id, 2);
		} else if(id < W + H){
			goal = func(id-W, W-1, 3);
		} else if(id < W + H + W){
			goal = func(H-1, W-1-(id-W-H), 0);
		} else if(id < W + H + W + H){
			goal = func(H-1-(id-W-H-W), 0, 1);
		}
		
		// cout << id << ' ' << goal << endl;
		
		if(goal != input[i+1]) return false;
	}
	
	return true;
}

void main2(void){
	int i,j;
	
	cin >> H >> W;
	int N = 2 * (H + W);
	REP(i,N) cin >> input[i];
	REP(i,N) input[i]--;
	
	int mask;
	
	REP(mask,(1<<H*W)){
		REP(i,H) REP(j,W){
			int t = (1 << (i * W + j));
			if(mask&t) board[i][j] = '/'; else board[i][j] = '\\';
		}
		
		if(check()){
			REP(i,H){
				string s;
				REP(j,W) s += board[i][j];
				cout << s << endl;
			}
			return;
		}
	}
	
	cout << "IMPOSSIBLE" << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d:\n", tc+1);
		main2();
	}
	return 0;
}
