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
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    vector<int> hs(n);
    for(int i = 0; i < n; i++){
        cin >> hs[i];
        // scanf("%d", &hs[i]);
    }
    sort(hs.rbegin(), hs.rend());
    auto solve = [&](int num){
        int cnt = num;
        for(int i = 0; i < n; i++){
            ll hp = hs[i] - b * num;
            if(hp <= 0){ break; }
            cnt -= (hp + a - b - 1) / (a - b);
            if(cnt < 0){
                break;
            }
        }
        return cnt >= 0;
    };
    int l = 0, r = 1e9;
    while(l < r){
        int piv = (l + r) / 2;
        if(solve(piv)){
            r = piv;
        }else{
            l = piv + 1;
        }
        prints(l, r);
    }
    cout << l << '\n';
    return 0;
}