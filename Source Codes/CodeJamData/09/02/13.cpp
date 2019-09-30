#include <iostream>

using namespace std;

int memo[110][110];
int map[110][110];
int h, w;
//bool isbasin[110][110];

char label[26];
int bascnt;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int dp(int x, int y){
	if (memo[x][y] != -1) return memo[x][y];
	int best = map[x][y], besti = -1;
	for (int i = 0; i < 4; i++){
		int newx = x + dx[i], newy = y+dy[i];
		if (newx >= 0 && newx < h && newy >= 0 && newy < w && map[newx][newy] < best){
			best = map[newx][newy];
			besti = i;
		}
	}
	memo[x][y] = dp(x+dx[besti],y+dy[besti]);
	return memo[x][y];
}

int main(){
	int n; cin >> n;
	for (int zzz = 1; zzz <= n; zzz++){
		cin >> h >> w;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++){
				memo[i][j] = -1;
				cin >> map[i][j];
				//isbasin[i][j] = false;
			}
		bascnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++){
				bool basin = true;
				for (int k = 0; k < 4; k++){
					int newx = i + dx[k], newy = j+dy[k];
					if (newx >= 0 && newx < h && newy >= 0 && newy < w && map[newx][newy] < map[i][j])
						basin = false;
				}
				if (basin){
					//label[make_pair(i,j)] = bascnt++;
					//isbasin[i][j] = true;
					memo[i][j] = bascnt++;
				}
			}
		for (int i = 0; i < 26; i++)
			label[i] = -1;
		int cnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++){
				if (label[dp(i,j)] == -1){
					label[dp(i,j)] = cnt + 'a';
					cnt++;
				}
			}
		cout << "Case #" << zzz << ":" << endl;
		for (int i = 0; i < h; i++){
			cout << label[dp(i,0)];
			for (int j = 1; j < w; j++)
				cout << " " << label[dp(i,j)];
			cout << endl;
		}
		
	}
	return 0;
}
