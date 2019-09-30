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
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <ostream& out = cout, class... T> void prints(T&&...){ }
template <ostream& out = cout, class... T> void printd(T&&...){ }
template <ostream& out = cout, class... T> void printb(T&&...){ }
template <ostream& out = cout, class... T> void printArr(T&&...){ }
#endif

int main(){
    int r, c, n;
    cin >> r >> c >> n;
    struct Elem{
        int lst, beg, color;
        bool operator < (const Elem& e) const{
            return lst != e.lst ? lst < e.lst : beg != e.beg ? beg < e.beg : color < e.color;
        }
        bool operator == (const Elem& e) const{
            return lst == e.lst && beg == e.beg && color == e.color;
        }
    };
    int cnt = 0;
    set<Elem> ve = {{r + r + c + c, 0, -1}};
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if((x1 != 0 && x1 != r && y1 != 0 && y1 != c) ||
           (x2 != 0 && x2 != r && y2 != 0 && y2 != c)){
            continue;
        }
        int pos1, pos2;
        if(x1 == 0){ pos1 = y1; }else if(x1 == r){ pos1 = c + r + c - y1; }else if(y1 == 0){ pos1 = c + r + c + r - x1; }else{ pos1 = c + x1; }
        if(x2 == 0){ pos2 = y2; }else if(x2 == r){ pos2 = c + r + c - y2; }else if(y2 == 0){ pos2 = c + r + c + r - x2; }else{ pos2 = c + x2; }
        v.emplace_back(pos1, cnt);
        v.emplace_back(pos2, cnt++);
        // if(pos1 > pos2){
        //     swap(pos1, pos2);
        // }
        // // auto e1 = lower_bound(ve.begin(), ve.end(), Elem{pos1, -1, 0});
        // // auto e2 = lower_bound(ve.begin(), ve.end(), Elem{pos2, -1, 0});
        // auto e1 = ve.lower_bound(Elem{pos1, -1, 0});
        // auto e2 = ve.lower_bound(Elem{pos2, -1, 0});
        // if(e1->color != e2->color){
        //     cout << "NO" << '\n';
        //     return 0;
        // }
        // int color = cnt++;
        // if(*e1 == *e2){
        //     ve.insert({e1->lst, pos2, e1->color});
        //     ve.insert({pos2, pos1, color});
        //     ve.insert({pos1, e1->beg, e1->color});
        //     ve.erase(*e1);
        // }else{
        //     ve.insert({e2->lst, pos2, e1->color});
        //     ve.insert({pos2, e2->beg, color});
        //     ve.insert({e1->lst, pos1, color});
        //     ve.insert({pos1, e1->beg, e1->color});
        //     ve.erase(*e1);
        //     ve.erase(*e2);
        // }
    }
    sort(v.begin(), v.end());
    vector<int> st;
    for(auto p : v){
        int i = p.second;
        if(st.size() && st.back() == i){
            st.pop_back();
        }else{
            st.push_back(i);
        }
    }
    cout << (st.empty() ? "YES" : "NO") << '\n';
    return 0;
}