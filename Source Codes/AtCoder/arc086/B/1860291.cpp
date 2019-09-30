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
    vector<int> as(n);
    int pc = 0, mc = 0, maxi = -M, mini = M, maxIdx = 0, minIdx = 0;
    for(int i = 0; i < n; i++){
        cin >> as[i];
        pc += as[i] > 0;
        mc += as[i] < 0;
        if(maxi < as[i]){
            maxi = as[i];
            maxIdx = i;
        }
        if(as[i] < mini){
            mini = as[i];
            minIdx = i;
        }
    }
    vector<pair<int, int>> ans;
    auto add = [&](int d, int f){ 
        ans.emplace_back(f, d);
        as[d] += as[f];
    };
    auto sub = [&](int d, int f){ 
        ans.emplace_back(f, d);
        as[d] -= as[f];
    };
    if(abs(maxi) >= abs(mini)){
        add(0, maxIdx);
        add(0, maxIdx);
        for(int i = 1; i < n; i++){
            add(i, i - 1);
            add(i, i - 1);
        }
    }
    if(abs(maxi) < abs(mini)){
        sub(n - 1, minIdx);
        sub(n - 1, minIdx);
        for(int i = n - 2; i >= 0; i--){
            sub(i, i + 1);
            sub(i, i + 1);
        }
    }
    cout << ans.size() << '\n';
    for(auto& a : ans){
        cout << a.first + 1 << ' ' << a.second + 1 << '\n';
    }
}