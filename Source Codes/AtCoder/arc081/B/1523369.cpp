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
template <ostream& out = cout, class... T> void printde(T&&...){ }
template <ostream& out = cout, class... T> void printb(T&&...){ }
template <ostream& out = cout, class... T> void printArr(T&&...){ }
#endif

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int i = 0;
    bool h;
    ll ans = 1;
    if(s1[i] == s2[i]){
        ans *= 3;
        i++;
        h = false;
    }else{
        ans *= 6;
        i += 2;
        h = true;
    }
    for(; i < n; i++){
        if(s1[i] == s2[i]){
            ans *= h ? 1 : 2;
            ans %= M;
            h = false;
        }else{
            ans *= h ? 3 : 2;
            ans %= M;
            i++;
            h = true;
        }
    }
    cout << ans << '\n';
    return 0;
}