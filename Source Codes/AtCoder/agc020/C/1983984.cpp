#include<algorithm>
#include<bitset>
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
    int n; cin >> n;
    vector<int> as(n);
    int targ = 0;
    for(int i = 0; i < n; i++){
        cin >> as[i];
        targ += as[i];
    }
    targ = (targ + 1) / 2;
    bitset<(int)4e6 + 1> bs;
    bs[0] = 1;
    for(int i = 0; i < n; i++){
        bs |= bs << as[i];
    }
    for(int i = targ; i <= 4e6; i++){
        if(bs[i]){
            cout << i << '\n';
            return 0;
        }
    }
}