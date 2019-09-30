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
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ds(n, vector<int>(n, M));
    vector<int> as(m), bs(m), cs(m);
    for(int i = 0; i < m; i++){
        cin >> as[i] >> bs[i] >> cs[i];
        as[i]--; bs[i]--;
        ds[as[i]][bs[i]] = ds[bs[i]][as[i]] = cs[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ds[j][k] = min(ds[j][k], ds[j][i] + ds[i][k]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(ds[as[i]][bs[i]] != cs[i]){
            ans++;
        }
    }
    cout << ans << '\n';
}