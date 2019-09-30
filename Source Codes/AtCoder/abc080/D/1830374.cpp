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

struct Stuple {
    int s; int t; int c;
    using type = tuple<int, int, int>;
    Stuple(int s, int t, int c): s(s), t(t), c(c){ }
    operator tuple<int, int, int> () const { return make_tuple(s, t, c); }
    // bool operator < (const Stuple& e) const { return type(*this) < type(e); }
    // ostream& operator >> (ostream& out) const { prints(type(*this)); return out; }
    bool operator < (const Stuple& e) const { return tie(s, t, c) < tie(e.s, e.t, e.c); }
    ostream& operator >> (ostream& out) const { prints(tie(s, t, c)); return out; }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, c;
    cin >> n >> c;
    // set<tuple<int, int, int>> stcs;
    set<Stuple> stcs;
    for(int i = 0; i < n; i++){
        int s, t, c;
        cin >> s >> t >> c;
        stcs.emplace(s, t, c);
    }
    int ans = 0;
    prints(stcs);
    while(stcs.size()){
        ans++;
        auto next = stcs;
        int time = -1, channel = -1;
        for(auto& stc : stcs){
            // if(time + (channel != get<2>(stc)) <= get<0>(stc)){
            //     time = get<1>(stc);
            //     channel = get<2>(stc);
            //     next.erase(stc);
            // }
            // get<0>(stc.data) = 1;
            // decltype(auto) a = get<0>(stc.data);
            // a = 1;
            // stc.t = 1;
            if(time + (channel != stc.c) <= stc.s){
                time = stc.t;
                channel = stc.c;
                next.erase(stc);
            }
        }
        next.swap(stcs);
    }
    cout << ans << '\n';
}