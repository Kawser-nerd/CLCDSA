#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

struct Node{
    int pos;
    int rem;
    int mag;
    Node(int p, int r, int m):pos(p), rem(r), mag(m){}
};

int main(){
    const int DY[4] = {-1, 0, 1, 0};
    const int DX[4] = {0, 1, 0, -1};
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> field(H);
    REP(i, H)cin >> field[i];
    int start = 0;
    REP(y,H)REP(x,W)if(field[y][x]=='S'){
        start = y*W+x;
    }
    vector<int> used(H*W);
    vector<int> next;
    queue<pair<int, int> > que;
    que.push(make_pair(start, K));
    while(!que.empty()){
        pair<int, int> n = que.front();que.pop();
        int p = n.first;
        if(used[p])continue;
        used[p] = 1;
        next.push_back(p);
        if(n.second==0)continue;
        int cy = p / W;
        int cx = p % W;
        REP(i, 4){
            int ny = cy + DY[i];
            int nx = cx + DX[i];
            if(ny<0 || nx<0 || ny>=H || nx>=W)continue;
            if(field[ny][nx]=='#')continue;
            que.push(make_pair(ny*W+nx, n.second-1));
        }
    }
    REP(i, next.size()){
        que.push(make_pair(next[i], 0));
    }
    int res = -1;
    used.assign(H*W, -1);
    while(!que.empty()){
        pair<int, int> n = que.front();que.pop();
        int p = n.first;
        if(used[p]!=-1)continue;
        used[p] = n.second;
        int cy = p / W;
        int cx = p % W;
        if(cy==0 || cx==0 || cy==H-1 || cx==W-1){
            res = n.second;
            break;
        }
        REP(i, 4){
            int ny = cy + DY[i];
            int nx = cx + DX[i];
            if(ny<0 || nx<0 || ny>=H || nx>=W)continue;
            que.push(make_pair(ny*W+nx, n.second+1));
        }
    }
    res = res / K + (res % K > 0 ? 1 : 0) + 1;
    cout << res << endl;

    return 0;
}