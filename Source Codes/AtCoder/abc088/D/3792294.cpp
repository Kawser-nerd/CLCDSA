#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int h, w;
    const int INF = 50 * 50;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> d;
    d.resize(h);
    for (int i = 0; i < h; ++i){
        cin >> s[i];
        d[i].resize(w);
    }
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j){
            d[i][j] = INF;
        }
    }

    // search
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    d[0][0] = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(0 <= nx && nx < h && 0 <= ny && ny < w && d[nx][ny] == INF && s[nx][ny] != '#'){
                q.push(make_pair(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    if(d[h-1][w-1] == INF){
        cout << -1 << endl;
    }
    else {
        int itr = 0;
        int ans = 0;
        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                if(s[i][j] == '.'){
                    ans++;
                }
            }
        }
        ans -= (d[h-1][w-1] + 1);
        cout << ans << endl;
    }
    return 0;
}