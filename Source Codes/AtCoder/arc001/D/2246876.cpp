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

void search(vector<P> q, int d){
    if(d == 5){
        vector<vector<char>> ans(8, vector<char>(8, '.'));
        for(int i = 0; i < 8; i++){
            ans[q[i].first][q[i].second] = 'Q';
        }
        rep(i, 8){
            rep(j, 8){
                cout << ans[i][j];
            }
            cout << endl;
        }
        exit(0);
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            bool f = true;
            for(int k = 0; k < (int)q.size(); k++){
                int sx = abs(q[k].first - i);
                int sy = abs(q[k].second - j);
                if(sx == sy || sx == 0 || sy == 0){
                    f = false;
                }
            }
            if(f){
                q.push_back(make_pair(i, j));
                search(q, d+1);
                q.pop_back();
            }
        }
    }
}

signed main(){
    vector<P> q;
    rep(i, 8){
        rep(j, 8){
            char c;
            cin >> c;
            if(c == 'Q'){
                q.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0; i < (int)q.size(); i++){
        for(int j = 0; j < (int)q.size(); j++){
            if(i == j){
                continue;
            }
            int sx = abs(q[i].first - q[j].first);
            int sy = abs(q[i].second - q[j].second);
            if(sx == sy || sx == 0 || sy == 0){
                cout << "No Answer" << endl;
                return 0;
            }
        }
    }

    search(q, 0);
    cout << "No Answer" << endl;
    return 0;
}