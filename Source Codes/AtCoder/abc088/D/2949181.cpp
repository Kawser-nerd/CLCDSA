#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int inf = 1e9;
const ll linf = 1LL << 50;

int h, w;
string s[51];
bool used[51][51];
int dis[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(int argc, char const* argv[])
{
	cin >> h >> w;
	int sum = 0;
	for(int i = 0; i < h; i++){
			cin >> s[i];
			for(int j = 0; j < w; j++){
					if(s[i][j] == '#')sum++;
					used[i][j] = false;
					dis[i][j] = -1;
			}
	}
	queue<P> q;
	q.push(mk(0, 0));
	dis[0][0] = 0;
	used[0][0] = true;
	while(!q.empty()){
			P p = q.front(); q.pop();
			for(int i = 0; i < 4; i++){
					int nx = p.first + dx[i];
					int ny = p.second + dy[i];
					if(nx >= 0 && nx < h && ny >= 0 && ny < w && !used[nx][ny] && s[nx][ny] != '#'){
							used[nx][ny] = true;
							q.push(mk(nx, ny));
							dis[nx][ny] = dis[p.first][p.second] + 1;
					}
			}
	}
	if(dis[h-1][w-1] != -1)cout << h * w - sum - dis[h-1][w-1] -1 << endl;
	else cout << -1 << endl;
	return 0;
}