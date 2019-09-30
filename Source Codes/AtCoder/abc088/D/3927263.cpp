#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <bitset>
#include <string>
#include <array>
#include <queue>

using namespace std;

int main()
{
    int h, w;
    const int INF = 10000;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> d(h);
    for (int i=0; i<h; ++i){
        cin >> s[i];
        d[i].resize(w);
        for(int j=0; j<w; ++j){
            d[i][j] = INF;
        }
    }
    int dw[4] = {1, 0, -1, 0};
    int dh[4] = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    d[0][0] = 0;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        for(int i=0; i<4; ++i){
            int nh = p.first + dh[i];
            int nw = p.second + dw[i];
            if(0 <= nh && nh < h && 0 <= nw && nw < w && s[nh][nw] == '.' && d[nh][nw] == INF){
                q.push(make_pair(nh, nw));
                d[nh][nw] = d[p.first][p.second] + 1;
            }
        }
    }
    int ans = 0;
    if(d[h-1][w-1] == INF){
        ans = -1;
    }
    else {
    vector<bool> check(d[h-1][w-1]+1, false);
        for (int i=0; i<h; ++i){
            for (int j=0; j<w; ++j){
                if(s[i][j] == '.'){
                    ans++;
                }
            }
        }
        ans -= d[h-1][w-1] + 1;
    }
    cout << ans << endl;
    return 0;
}