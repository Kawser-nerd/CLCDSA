#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef tuple<ll, int, int> T;
#define rep(i,n) for(int i=0;i<(n);i++)
const ll INF = 1e9;

int h, w, t;
string s[12];
int sy, sx, gy, gx;
int dy[] = {1, 0, 0, -1};
int dx[] = {0, 1, -1, 0};

bool dijkstra(int m){
    ll memo[12][12];
    for (int i = 0; i < 12; ++i) {
        for (int k = 0; k < 12; ++k) {
            memo[i][k] = INF * 10;//m?????????????????
        }
    }
    priority_queue<T, vector<T>, greater<T> > q;
    q.push(make_tuple(0, sy, sx));
    memo[sy][sx] = 0;
    while(!q.empty()){
        ll c; int y, x;
        tie(c, y, x) = q.top(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
            if(s[ny][nx] == '#'){
                if(memo[ny][nx] > c + m){//??????
                    memo[ny][nx] = c + m;
                    q.push(make_tuple(c + m, ny, nx));
                }
            }else{//??????
                if(memo[ny][nx] > c + 1){
                    memo[ny][nx] = c + 1;
                    q.push(make_tuple(c + 1, ny, nx));
                }
            }
        }
    }
    if(memo[gy][gx] <= t) {
        return true;
    } else {
        return false;
    }
}

int main(void){
    cin >> h >> w >> t;
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < h; ++i) {
        for (int k = 0; k < w; ++k) {
            if(s[i][k] == 'S'){
                sy = i; sx = k;
            }else if(s[i][k] == 'G'){
                gy = i; gx = k;
            }
        }
    }

    ll l = 1, r = INF;
    while(r - l > 1){
        int x = (l + r) / 2;
        if(dijkstra(x)) {
            l = x;
        } else {
            r = x;
        }
    }
    printf("%d\n", l);
    return 0;
} ./Main.cpp:79:20: warning: format specifies type 'int' but the argument has type 'll' (aka 'long long') [-Wformat]
    printf("%d\n", l);
            ~~     ^
            %lld
1 warning generated.