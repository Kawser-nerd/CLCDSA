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
const int N = 19;

signed main(){
    vector<vector<char>> b(N, vector<char>(N));
    int bb, ww;
    bb = ww = 0;
    rep(i, N){
        rep(j, N){
            cin >> b[i][j];
            if(b[i][j] == 'o'){
                bb++;
            }
            if(b[i][j] == 'x'){
                ww++;
            }
        }
    }

    if(bb == 0 && ww == 0){
        cout << "YES" << endl;
        return 0;
    }

    if(bb - ww < 0 || bb - ww > 1){
        cout << "NO" << endl;
        return 0;
    }

    vector<int> dx = {1, 0, 1, -1};
    vector<int> dy = {0, 1, 1, 1};

    rep(k, N){
        rep(l, N){
            if(b[k][l] == '.'){
                continue;
            }
            char remove = b[k][l];
            b[k][l] = '.';

            bool isIllegal = false;

            rep(i, N){
                rep(j, N){
                    if(b[i][j] == '.'){
                        continue;
                    }

                    rep(k, 4){
                        int h = i;
                        int w = j;
                        int cnt = 0;
                        while(b[i][j] == b[h][w]){
                            cnt++;
                            h += dx[k];
                            w += dy[k];
                            if(h < 0 || h >= N || w < 0 || w >= N){
                                break;
                            }
                        }

                        if(cnt >= 5){
                            isIllegal = true;
                        }
                    }
                }
            }
            if(not isIllegal){
                if(remove == 'o' && bb > ww || remove == 'x' && bb == ww){
                    cout << "YES" << endl;
                    return 0;
                }
            }
            b[k][l] = remove;
        }
    }
    cout << "NO" << endl;

    return 0;
} ./Main.cpp:87:34: warning: '&&' within '||' [-Wlogical-op-parentheses]
                if(remove == 'o' && bb > ww || remove == 'x' && bb == ww){
                   ~~~~~~~~~~~~~~^~~~~~~~~~ ~~
./Main.cpp:87:34: note: place parentheses around the '&&' expression to silence this warning
                if(remove == 'o' && bb > ww || remove == 'x' && bb == ww){
                                 ^
                   (                       )
./Main.cpp:87:62: warning: '&&' within '||' [-Wlogical-op-parentheses]
                if(remove == 'o' && bb > ww || remove == 'x' && bb == ww){
                                            ~~ ~~~~~~~~~~~~~~^~~~~~~~~~~
./Main.cpp:87:62: note: place parentheses around the '&&' expression to silence this warning
                if(remove == 'o' && bb > ww || remove == 'x' && bb == ww){
                                                             ^
                                               (                        )
2 warnings generated.