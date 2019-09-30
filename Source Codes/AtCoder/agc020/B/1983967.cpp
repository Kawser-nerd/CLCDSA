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
using uint = unsigned int;
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k; cin >> k;
    vector<int> as(k);
    for(int i = 0; i < k; i++){
        cin >> as[i];
    }
    reverse(as.begin(), as.end());
    ll l = 2, r = 2;
    for(int i = 0; i < k; i++){
        int a = as[i];
        l = (l + a - 1) / a * a;
        r = r / a * a + a - 1;
        printd(l, r);
        if(l > r){
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << l << ' ' << r << '\n';
}