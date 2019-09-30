//{{{
#include<algorithm>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<list>
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
    int n, a, b;
    cin >> n >> a >> b;
    if(__builtin_popcount(a) % 2 == __builtin_popcount(b) % 2){
        cout << "NO" << '\n';
        return 0;
    }
    vector<int> ans;
    ans.push_back(a);
    int pos = a;
    vector<int> cnts(1 << n);
    unordered_set<int> used;
    used.insert(a);
    for(int j = 0; j < n; j++){
        cnts[a ^ (1 << j)]++;
    }
    for(int i = 0; i < (1 << n) - 1; i++){
        int next, mini = M;
        for(int j = 0; j < n; j++){
            int cand = pos ^ (1 << j);
            if(used.count(cand)){ continue; }
            if(cand == b && i != (1 << n) - 2){ continue; }

            if(-cnts[cand] < mini){
                mini = -cnts[cand];
                next = cand;
            }else if(-cnts[cand] == mini && __builtin_popcount(next ^ b) < __builtin_popcount(cand ^ b)){
                mini = cnts[cand];
                next = cand;
            }

            // int maxi = 0;
            // for(int k = 0; k < n; k++){
            //     int next = cand ^ (1 << k);
            //     if(!used.count(next)){
            //         maxi = max(maxi, cnts[next]);
            //     }
            // }
            // if(maxi < mini){
            //     mini = maxi;
            //     next = cand;
            // }

            // if(cnts[cand] < mini){
            //     mini = cnts[cand];
            //     next = cand;
            // }
        }
        if(mini == M){
            printde(ans);
            printde("error", i, 1 << n, pos);
            for(int j = 0; j < (1 << n); j++){
                if(used.count(j) == 0){
                    printde(j);
                }
            }
            return 1;
        }
        // printde(mini);
        ans.push_back(next);
        used.insert(next);
        cnts[next] = -1;
        for(int j = 0; j < n; j++){
            cnts[next ^ (1 << j)]++;
        }
        pos = next;
        // printde(cnts);
    }
    // printde(ans);
    cout << "YES" << '\n';
    for(auto& a : ans){
        cout << a << ' ';
    }
}