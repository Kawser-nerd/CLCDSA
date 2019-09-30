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
// #define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif

// template <class T>
// struct SegTreeT {
//     SegTreeT *l, *r;
//     int left, right;
//     T value = 0;
//     SegTreeT(vector<T>& data):SegTreeT(0, data.size() - 1, data){ }
//     SegTreeT(int st, int lt, vector<T>& data): left(st), right(lt){
//         if(left == right){
//             l = r = nullptr;
//             value = data[left];
//         }else{
//             l = new SegTreeT(left, (right - left) / 2 + left, data);
//             r = new SegTreeT((right - left) / 2 + left + 1, right, data);
//         }
//     }
//     void add(int st, int lt, T val){
//         if(right < st || lt < left){ return; }
//         if(st <= left && right <= lt){
//             value += val;
//         }else{
//             l -> add(st, lt, val);
//             r -> add(st, lt, val);
//         }
//     }
// 	T getVal(int idx){
//         if(right < idx || idx < left){ return 0; }
//         return value + (l ? l->getVal(idx) + r->getVal(idx) : 0);
// 	}
// };
// using SegTree = SegTreeT<int>;

template <class T>
struct SegTreeT{
    struct Node{
        int left, right;
        T value;
        bool outside(int pos){ return right < pos || pos < left; }
        bool outside(int st, int lt){ return right < st || lt < left; }
        bool inside(int st, int lt){ return st <= left && right <= lt; }
    };
    vector<Node> nodes;
    // SegTreeT(int num): nodes(num * 2){
    //     init(0, num);
    // }
    SegTreeT(vector<T>& data): nodes(data.size() * 3){
        init(0, data.size() - 1, data);
    }
    void init(int st, int lt, vector<T>& data, size_t idx = 1){
        nodes[idx].left = st; nodes[idx].right = lt;
        if(st == lt){
            nodes[idx].value = data[st];
        }else{
            init(st, (lt - st) / 2 + st, data, idx << 1);
            init((lt - st) / 2 + st + 1, lt, data, idx << 1 | 1);
        }
    }
    void add(int st, int lt, T val, size_t idx = 1){
        if(nodes[idx].outside(st, lt)){ return; }
        if(nodes[idx].inside(st, lt)){
            nodes[idx].value += val;
        }else{
            add(st, lt, val, idx << 1);
            add(st, lt, val, idx << 1 | 1);
        }
    }
    T getVal(int pos, size_t idx = 1){
        if(idx >= nodes.size() || nodes[idx].outside(pos)){ return 0; }
        return nodes[idx].value + getVal(pos, idx << 1) + getVal(pos, idx << 1 | 1);
    }
};
using SegTree = SegTreeT<int>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    vector<vector<int>> cs(255);
    for(size_t i = 0; i < s.size(); i++){
        cs[s[i]].push_back(i);
    }
    int r = s.size() - 1;
    int n = s.size();
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    SegTree st(v);
    vector<int> is(255);
    int odds = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        char c = s[i];
        int i1 = cs[c][is[c]], i2 = cs[c][cs[c].size() - 1 - is[c]];
        int p1 = st.getVal(i1), p2 = st.getVal(i2);
        if(i1 < i2){
            ans += abs(p1 - odds - (r - p2));
            st.add(i2 + 1, r, -1);
            // printd(c, i, p1, p2, abs(p1 - (r - p2)));
        }else if(i1 == i2){
            odds++;
            if(odds > 1){
                cout << -1 << '\n';
                return 0;
            }
            // if(p1 < n / 2){
                ans += abs(p1 - n / 2);
                // printd(c, i, p1, (int)s.size() / 2);
            // }
        }
        is[c]++;
    }
    cout << ans << '\n';
}