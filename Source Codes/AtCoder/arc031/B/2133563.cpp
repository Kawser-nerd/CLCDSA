#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int h = 10;
int w = 10;
int c = 1;

void bfs(const vector<vector<bool>>& a, vector<vector<int>>& r, pair<P, int> x) {
    if(not a[x.first.first][x.first.second] || r[x.first.first][x.first.second] != 0){
        return;
    }
    queue<pair<P, int>> q;
    q.push(x);

    while(not q.empty()){
        pair<P, int> p = q.front();
        q.pop();
        int x = p.first.first;
        int y = p.first.second;
        if(r[x][y] != 0){
            continue;
        }
        r[x][y] = p.second;

        if(x + 1 < h && a[x+1][y] && r[x+1][y] == 0){
            q.push(make_pair(make_pair(x+1, y), p.second));
        }

        if(x - 1 >= 0 && a[x-1][y] && r[x-1][y] == 0){
            q.push(make_pair(make_pair(x-1, y), p.second));
        }

        if(y + 1 < w && a[x][y+1] && r[x][y+1] == 0){
            q.push(make_pair(make_pair(x, y+1), p.second));
        }

        if(y - 1 >= 0 && a[x][y-1] && r[x][y-1] == 0){
            q.push(make_pair(make_pair(x, y-1), p.second));
        }
    }
    c++;
}
signed main(){
    vector<vector<bool>> area(h, vector<bool>(w, false));
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;
            if(c == 'o'){
                area[i][j] = true;
            }
        }
    }

    vector<vector<int>> r(h, vector<int>(w));
    rep(i, h){
        rep(j, w){
            bfs(area, r, make_pair(make_pair(i, j), c));
        }
    }

    vector<bool> x(h*w, false);
    rep(i, h){
        rep(j, w){
            x[r[i][j]] = true;
        }
    }

    int islands = 0;
    for(int i = 1; i < h*w; i++){
        if(x[i]){
            islands++;
        }
    }

    if(islands > 4){
        cout << "NO" << endl;
        return 0;
    }

    rep(i, h){
        rep(j, w){
            vector<bool> y(5, false);

            if(i + 1 < h){
                y[r[i+1][j]] = true;
            }
            if(i - 1 >= 0){
                y[r[i-1][j]] = true;
            }
            if(j + 1 < w){
                y[r[i][j+1]] = true;
            }
            if(j - 1 >= 0){
                y[r[i][j-1]] = true;
            }

            int c = 0;
            for(int k = 1; k <= 4; k++){
                if(y[k]){
                    c++;
                }
            }
            if(c == islands){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}