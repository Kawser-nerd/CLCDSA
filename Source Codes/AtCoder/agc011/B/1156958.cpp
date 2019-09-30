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
    vector<ll> as(n);
    for(int i=0;i<n;i++){
        cin >> as[i];
    }
    sort(as.begin(), as.end());
    vector<ll> accs = as;
    for(int i=1;i<n;i++){
        accs[i] += accs[i - 1];
    }
    prints(as, accs);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(i + 1 == as.size() || accs[i] * 2 >= as[i + 1]){
            ans++;
        }else{
            ans = 0;
        }
        // if(!i || as[i - 1] <= 2 * as[i]){
        //     ans++;
        // }else{
        //     break;
        // }
    }
    cout << ans << '\n';
    return 0;
}