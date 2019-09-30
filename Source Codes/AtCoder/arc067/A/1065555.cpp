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

int main(){
    int n; cin >> n;
    map<int, int> factors;
    for(int i=2;i<=n;i++){
        int num = i;
        for(int j=2;j<=n;j++){
            while(num % j == 0){
                num /= j;
                factors[j]++;
            }
        }
    }
    ll ans = 1;
    for(auto p : factors){
        ans = ans * (p.second + 1) % M;
    }
    prints(factors);
    cout << ans << '\n';
    return 0;
}