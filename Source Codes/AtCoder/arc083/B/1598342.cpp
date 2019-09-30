#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using uint = unsigned int;
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd);
#endif

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> as(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> as[i][j];
        }
    }
    ll ans = 0;
    unordered_set<int> us;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i == j || i == k || j == k){ continue; }
                if(as[i][j] + as[j][k] < as[k][i]){
                    cout << -1 << '\n';
                    return 0;
                }
                // if(as[i][j] + as[j][k] > as[k][i] && !us.count(k * 1000 + i)){
                //     us.insert(k * 1000 + i);
                //     ans += as[k][i];
                //     prints(k, i, as[k][i]);
                // }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int k = 0; k < n; k++){
                if(i == j || i == k || j == k){ continue; }
                if(as[i][j] < as[i][k] + as[k][j]){
                    cnt++;
                }
            }
            if(cnt == n - 2){
                ans += as[i][j];
            }
        }
    }
    cout << ans / 2 << '\n';
    return 0;
}