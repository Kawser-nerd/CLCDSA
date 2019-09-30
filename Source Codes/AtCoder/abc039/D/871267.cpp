#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <cassert>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define ALL(a) (a).begin(),(a).end()

#define pb push_back

using namespace std;
typedef unsigned long ul;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;

typedef pair<int, int> P;

int h, w;
char s[101][101];
char black[101][101];
int v[3] = {-1, 0, 1};

bool check(int y, int x){
    map<P,bool> mp;
    for (int i : v){
        for (int j : v){
            int xx=x+i;
            int yy=y+j;
            if (xx < 0 || xx >= w || yy < 0 || yy >= h) continue;
            if (s[yy][xx] != '#') return false;
            mp[make_pair(yy,xx)] = true;
        }
    }

    for (int i : v){
        for (int j : v){
            int xx=x+i;
            int yy=y+j;
            if (xx < 0 || xx >= w || yy < 0 || yy >= h) continue;
            if (mp[make_pair(yy,xx)] && black[yy][xx] != '#'){
                black[yy][xx] = '#';
            }
        }
    }

    return true;
}

int main() {
    cin >> h >> w;
    char o[h][w];
    REP(i,h) scanf("%s", s[i]);

    REP(i,h){
        REP(j,w){
            if (s[i][j] == '#' && check(i,j)){
                o[i][j] = '#';
            } else {
                o[i][j] = '.';
            }
        }
    }

    bool ok = true;
    for (int i = 0; ok && i < h; i++){
        for (int j = 0; ok && j < w; j++){
            if (s[i][j] == '#' && black[i][j] != s[i][j]){
                ok = false;
            }
        }
    }

    if (ok) {
        cout << "possible" << endl;
        REP(i,h){
            REP(j,w){
                printf("%c",o[i][j]);
            }
            printf("\n");
        }
    } else {
        cout << "impossible" << endl;
    }

}