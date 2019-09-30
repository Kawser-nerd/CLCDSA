#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
#include <complex>

using namespace std;
typedef long long ll;
typedef double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;

bool maze_rc[1<<7][1<<7];
bool maze_diag[1<<7][1<<7];
bool modified[1<<7][1<<7];
bool done_r[1<<8];
bool done_c[1<<8];
bool done_dp[1<<8];
bool done_dm[1<<8];
int offset = (1<<7);

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		int n, m; cin >> n >> m;
		memset(maze_rc, false, sizeof(maze_rc));
		memset(maze_diag, false, sizeof(maze_diag));
		memset(modified, false, sizeof(modified));
		memset(done_r, false, sizeof(done_r));
		memset(done_c, false, sizeof(done_c));
		memset(done_dp, false, sizeof(done_dp));
		memset(done_dm, false, sizeof(done_dm));
		
		int score = 0;
		int mod_cnt = 0;
		
		for (int i = 0; i < m; i++){
			char c; int r,s;
			cin >> c >> r >> s;
			if (c == 'o' || c == 'x'){
				maze_rc[r][s] = true;
				done_r[r] = true;
				done_c[s] = true;
				score++;
			}
			if (c == 'o' || c == '+'){
				maze_diag[r][s] = true;
				done_dp[r+s] = true;
				done_dm[r-s+offset] = true;
				score++;
			}
		}
		
		for (int i = 1; i <= n; i++){
			if (done_r[i]) continue;
			for (int j = 1; j <= n; j++){
				if (!done_c[j]){
					maze_rc[i][j] = true;
					done_r[i] = true;
					done_c[j] = true;
					if (!modified[i][j]) mod_cnt++;
					modified[i][j] = true;
					score++;
					break;
				}
			} 
		}
		for (int i = 2; i <= 2*n; i++){
			if (done_dp[i]) continue;
			int ma;
			if (i <= n+1) ma = i-2;
			else ma = 2*n-i;
			for (int j = ma; j >= 0; j-=2){
				if (!done_dm[offset+j]){
					int r = (i+j)/2;
					int s = (i-j)/2;
					maze_diag[r][s] = true;
					done_dp[i] = true;
					done_dm[offset+j] = true;
					if (!modified[r][s]) mod_cnt++;
					modified[r][s] = true;
					score++;
					break;
				}
				else if (!done_dm[offset-j]){
					int r = (i-j)/2;
					int s = (i+j)/2;
					maze_diag[r][s] = true;
					done_dp[i] = true;
					done_dm[offset-j] = true;
					if (!modified[r][s]) mod_cnt++;
					modified[r][s] = true;
					score++;
					break;
				}
			}
		}
		cout << "Case #" << zz << ": " << score << " " << mod_cnt << endl;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (modified[i][j]){
					if (maze_rc[i][j] && maze_diag[i][j]) cout << 'o';
					else if (maze_rc[i][j]) cout << 'x';
					else if (maze_diag[i][j]) cout << '+';
					cout << " " << i << " " << j << endl;
				}
	}
	
	return 0;
}
