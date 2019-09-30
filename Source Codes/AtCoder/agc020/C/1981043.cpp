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
    int n; cin >> n;
    int maxi = 0;
    vector<pair<int, int>> areas;
    areas.emplace_back(0, 1); // b, e
    vector<int> as(n);
    for(int i = 0; i < n; i++){
        cin >> as[i];
    }
    sort(as.begin(), as.end());
    for(int i = 0; i < n; i++){
        int a = as[i];
        int cnt = 1;
        // while(i < n && a == as[i]){ i++; cnt++; }
        // i--;
        maxi += a * cnt;
        vector<pair<int, int>> a2, a3;
        for(auto& area : areas){
            for(int i = 1; i <= cnt; i++){
                a2.emplace_back(area.first + a * i, area.second + a * i);
            }
        }
        size_t i1 = 0, i2 = 0;
        a3.push_back(areas[i1]);
        i1++;
        auto push = [&](vector<pair<int, int>> &v, size_t& idx){
            if(a3.back().second < v[idx].first){
                a3.push_back(v[idx]);
            }else{
                a3.back().second = max(a3.back().second, v[idx].second);
            }
            idx++;
        };
        while(i1 < areas.size() || i2 < a2.size()){
            if(i2 == a2.size() || (i1 < areas.size() && areas[i1] < a2[i2])){
                push(areas, i1);
            }else{
                push(a2, i2);
            }
        }
        areas.swap(a3);
    }
    // printd(areas);
    printd(areas.size());
    int ans = M, targ = (maxi + 1) / 2;
    for(auto& area : areas){
        if(area.second - 1 >= targ){
            // printd(ans, area);
            ans = min(ans, max(targ, area.first));
        }
    }
    cout << ans << '\n';
}