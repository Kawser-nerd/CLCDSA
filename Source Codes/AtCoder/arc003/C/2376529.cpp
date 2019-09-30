#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int n, m;
P s, g;

bool bfs(const vector<vector<int>>& area, const vector<vector<double>>& bright, double limit){
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    visit[s.first][s.second] = true;

    queue<pair<P, int>> q;
    q.emplace(s, 0);

    while(not q.empty()){
        pair<P, int> p = q.front();
        q.pop();

        int x = p.first.first;
        int y = p.first.second;
        int t = p.second;

        if(x + 1 < n && not visit[x+1][y] && area[x+1][y] >= 0){
            if(area[x+1][y] == 0){
                return true;
            }
            if(limit <= bright[area[x+1][y]][t+1]){
                q.emplace(make_pair(x+1, y), t+1);
                visit[x+1][y] = true;
            }
        }
        if(y + 1 < m && not visit[x][y+1] && area[x][y+1] >= 0){
            if(area[x][y+1] == 0){
                return true;
            }
            if(limit <= bright[area[x][y+1]][t+1]){
                q.emplace(make_pair(x, y+1), t+1);
                visit[x][y+1] = true;
            }
        }
        if(x - 1 >= 0 && not visit[x-1][y] && area[x-1][y] >= 0){
            if(area[x-1][y] == 0){
                return true;
            }
            if(limit <= bright[area[x-1][y]][t+1]){
                q.emplace(make_pair(x-1, y), t+1);
                visit[x-1][y] = true;
            }
        }
        if(y - 1 >= 0 && not visit[x][y-1] && area[x][y-1] >= 0){
            if(area[x][y-1] == 0){
                return true;
            }
            if(limit <= bright[area[x][y-1]][t+1]){
                q.emplace(make_pair(x, y-1), t+1);
                visit[x][y-1] = true;
            }
        }
    }
    return false;
}

signed main(){
    cin >> n >> m;

    vector<vector<int>> area(n, vector<int>(m));
    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;
            if(c == 's'){
                s = make_pair(i, j);
                area[i][j] = -1;
                continue;
            }
            if(c == 'g'){
                g = make_pair(i, j);
                continue;
            }
            if(c == '#'){
                area[i][j] = -1;
                continue;
            }
            area[i][j] = c - '0';
        }
    }

    vector<vector<double>> bright(10, vector<double>(n*m));
    bright[1][1] = 0.99;
    for(int i = 2; i < n * m; i++){
        bright[1][i] = bright[1][i-1] * 0.99;
    }
    for(int i = 2; i < 10; i++){
        for(int j = 1; j < n * m; j++){
            bright[i][j] = bright[1][j] * i;
        }
    }

    if(not bfs(area, bright, 0.0)){
        cout << -1 << endl;
        return 0;
    }

    double left = 0;
    double right = 10;
    for(int i = 0; i < 100; i++){
        double mid = left + (right - left) / 2;
        if(bfs(area, bright, mid)){
            left = mid;
        }else{
            right = mid;
        }
    }

    cout << fixed << setprecision(10) << left << endl;

    return 0;
}