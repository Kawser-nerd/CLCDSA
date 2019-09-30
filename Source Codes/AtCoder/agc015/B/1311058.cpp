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
template <class... T> void printArr(T&&...){ }
#endif

int main(){
    string ss; cin >> ss;
    int n = ss.size();
    ll ans = (n - 1) * 2;
    for(int i = 1; i < n - 1; i++){
        char c = ss[i];
        if(c == 'U'){
            ans += n - i - 1;
            ans += i * 2;
        }else{
            ans += (n - i - 1) * 2;
            ans += i;
        }
    }
    cout << ans << '\n';
    return 0;
}