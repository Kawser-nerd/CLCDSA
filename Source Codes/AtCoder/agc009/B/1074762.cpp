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
#include"basic.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
#endif

vector<int> as;
map<int, set<int>> mp;
int func(int win){
    auto& s = mp[win];
    vector<int> rets;
    for(int i : s){
        rets.push_back(func(i));
    }
    sort(rets.begin(), rets.end());
    int prev = -1;
    prints(win, rets);
    for(int i : rets){
        if(prev >= i){
            i = prev + 1;
        }
        prev = i;
    }
    return prev + 1;
}

int main(){
    int n; cin >> n;
    as.resize(n + 10);
    for(int i=2;i<n+2;i++){
        cin >> as[i];
        mp[as[i]].insert(i);
    }
    cout << func(1) << '\n';
    return 0;
}