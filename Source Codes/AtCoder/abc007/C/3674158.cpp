#include <iostream>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

int main()
{
    const int INF = 10000;
    int si, sj, gi, gj, w, h, ni, nj;
    pair<int, int> tmp_p;
    cin >> h >> w >> si >> sj >> gi >> gj;
    si--;
    sj--;
    gi--;
    gj--;
    vector<string> field(h);
    vector<vector<int>> d;
    d.resize(h);
    queue<pair<int, int>> q;
    for(int i=0; i<h; ++i){
        cin >> field[i];
        d[i].resize(w);
        for(int j=0; j<w; ++j){
            d[i][j] = INF;
        }
    }
    // push start point
    q.push(make_pair(si, sj));
    d[si][sj] = 0;
    while(!q.empty()){
        tmp_p = q.front();
        q.pop();
        ni = tmp_p.first;
        nj = tmp_p.second;
        // up
        if(0 <= ni-1 && d[ni-1][nj] == INF && field[ni-1][nj] == '.'){
            d[ni-1][nj] = d[ni][nj] + 1;
            q.push(make_pair(ni-1, nj));
        }
        // down
        if(ni+1 < h && d[ni+1][nj] == INF && field[ni+1][nj] == '.'){
            d[ni+1][nj] = d[ni][nj] + 1;
            q.push(make_pair(ni+1, nj));
        }
        // left
        if(0 <= nj-1 && d[ni][nj-1] == INF && field[ni][nj-1] == '.'){
            d[ni][nj-1] = d[ni][nj] + 1;
            q.push(make_pair(ni, nj-1));
        }
        // right
        if(nj+1 < w && d[ni][nj+1] == INF && field[ni][nj+1] == '.'){
            d[ni][nj+1] = d[ni][nj] + 1;
            q.push(make_pair(ni, nj+1));
        }
    }
    cout << d[gi][gj] << endl;
    return 0;
}