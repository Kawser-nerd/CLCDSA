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
    int w1, w2;
    cin >> w1 >> w2;
    int s1, s2;
    cin >> s1 >> s2;
    int e; cin >> e;
    int lim; cin >> lim;
    vector<int> dp(4001);
    dp[0] = 1;
    for(int i = 0; i <= 3000; i++){
        if(dp[i]){
            dp[i + s1] = dp[i + s2] = 1;
        }
    }
    int a1 = w1 * 100, a2 = 0;
    double maxi = 0;
    for(int i = 0; i <= 30; i++){
        for(int j = 0; j <= 30; j++){
            for(int k = 0; k <= 3000; k++){
                if(dp[k] == 0){ continue; }
                int water = 100 * (w1 * i + w2 * j);
                int sugar = k;
                if(water == 0 || water + sugar > lim){ continue; }
                if(water * e / 100 < sugar){ continue; }
                double d = 100.0 * sugar / (water + sugar);
                if(d > maxi){
                    maxi = d;
                    a1 = water + sugar;
                    a2 = sugar;
                }
            }
        }
    }
    cout << a1 << ' ' << a2 << '\n';
    return 0;
}