//{{{
#include<algorithm>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<random>
#include<set>
#include<sstream>
#include<sys/time.h>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printw) FUNC(printwe) FUNC(printb) FUNC(printbe) FUNC(printd) FUNC(printde) FUNC(printdu);
#endif
template <class S, class T>
istream& operator >> (istream& in, pair<S, T>& p){ return in >> p.first >> p.second; }
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }
//}}}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> bs(n); cin >> bs;
    vector<int> ans;
    for(int i = n; i > 0; i--){
        bool ok = false;
        for(int j = i - 1; j >= 0; j--){
            if(bs[j] == j + 1){
                ans.push_back(bs[j]);
                for(int j2 = j; j2 < n - 1; j2++){
                    bs[j2] = bs[j2 + 1];
                }
                n--;
                ok = true;
                break;
            }
        }
        bs.resize(n);
        printde(bs);
        if(!ok){
            cout << -1 << '\n';
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto& a : ans){
        cout << a << '\n';
    }
}