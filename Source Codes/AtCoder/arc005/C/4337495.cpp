#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>
#include <cmath>
#include <cassert>
#include <deque>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define show(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int h,w;
bool ok(int i,int j){
    return 0<=i and i < h and 0<= j and j < w;
}
int dist[505][505];
int c[505][505];
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
int main(){
    cin >> h >> w;
    int t,tt;
    int l,ll;
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w){
            if(s[j] == '#')c[i][j]=1;
            if(s[j] == 's'){
                t = i;
                tt = j;
            }
            if(s[j] == 'g'){
                l = i;
                ll = j;
            }
        }
    }
    rep(i,h)rep(j,w)dist[i][j] = 1<<30;
    dist[t][tt] = 0;
    deque<pii>q;
    q.emplace_back(t,tt);
    while(q.size()){
        auto x = q.front();
        q.pop_front();
        rep(i,4){
            int a = x.first + dx[i];
            int b = x.second + dy[i];
            if(ok(a,b) and dist[a][b] > dist[x.first][x.second] + c[a][b]){
                dist[a][b] = dist[x.first][x.second] + c[a][b];
                if(c[a][b])q.push_back({a,b});
                else q.push_front({a,b});
            }
        }
    }
    if(dist[l][ll] <= 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}