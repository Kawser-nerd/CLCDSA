#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
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
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
template <class... T> void printd(T&&...){ }
#endif

int main(){
    int n, l, t;
    cin >> n >> l >> t;
    vector<int> ls, rs, poss;
    int pos0 = -1, idx0;
    for(int i=0;i<n;i++){
        int x, w;
        cin >> x >> w;
        if(w == 1){
            rs.push_back(x);
            if(pos0 == -1){
                idx0 = i;
                pos0 = ((x + (w == 1 ? 1 : -1) * t + 1ll * l * t) % l);
            }
        }else{
            ls.push_back(x);
        }
        // cout << (x + (w == 1 ? 1 : -1) * t) % l << '\n';
        poss.push_back((x + (w == 1 ? 1 : -1) * t + 1ll * l * t) % l);
    }
    if(rs.empty()){
        for(int i=0;i<n;i++){
            cout << poss[i] << '\n';
        }
        return 0;
    }
    prints(poss);
    int cols = t / l * 2 * ls.size();
    t %= l;
    for(int lpos : ls){
        int p0 = rs[0] + t,
            p1 = lpos - t;
        if(rs[0] > lpos){
            p1 += l;
        }
        if(p0 < p1){
        }else if(p0 >= p1 + l){
            cols += 2;
            prints(p0, p1, cols);
        }else{
            cols++;
        }
    }
    printd(cols);
    int antPos0 = (idx0 + cols) % n;
    sort(poss.begin(), poss.end());
    int idx = 0;
    while(poss[idx] != pos0){ idx++; }
    if(poss[(idx + 1) % n] == pos0){
        idx = (idx + 1) % n;
    }
    printd(idx, pos0);
    vector<int> anss(n);
    for(int i=0;i<n;i++){
        anss[antPos0] = poss[idx];
        antPos0 = (antPos0 + 1) % n;
        idx = (idx + 1) % n;
    }
    for(int i=0;i<n;i++){
        cout << anss[i] << '\n';
    }
    return 0;
}