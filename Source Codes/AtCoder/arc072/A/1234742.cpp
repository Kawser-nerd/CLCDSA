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
    int n; cin >> n;
    vector<int> as(n);
    for(int i=0;i<n;i++){
        cin >> as[i];
    }
    ll ans = MLL;
    for(int h=0;h<2;h++){
        ll cand = 0, sum = 0;
        for(int i=0;i<n;i++){
            sum += as[i];
            if((i & 1) ^ h){
                if(sum <= 0){
                    cand += max(- sum + 1, 0ll);
                    sum = 1;
                }
            }else{
                if(sum >= 0){
                    cand += max(sum + 1, 0ll);
                    sum = -1;
                }
            }
        }
        ans = min(ans, cand);
    }
    cout << ans << '\n';
    return 0;
}