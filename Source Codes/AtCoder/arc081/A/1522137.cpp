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
    unordered_map<int, int> um;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        um[a]++;
    }
    vector<int> as2;
    for(auto p : um){
        if(p.second >= 4){
            as2.push_back(p.first);
        }
        if(p.second >= 2){
            as2.push_back(p.first);
        }
    }
    sort(as2.rbegin(), as2.rend());
    cout << (as2.size() < 2 ? 0 : 1ll * as2[0] * as2[1]) << '\n';
    return 0;
}