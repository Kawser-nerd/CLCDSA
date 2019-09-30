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
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(auto& p : mp){
        if(p.first < p.second){
            ans += p.second - p.first;
        }else if(p.first > p.second){
            ans += p.second;
        }
    }
    cout << ans << '\n';
}