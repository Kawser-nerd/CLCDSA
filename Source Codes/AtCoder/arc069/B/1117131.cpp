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

int n;
string s;
void solve(bool fs, bool ls){
    bool ps, ps2, pw, pw2;
    ps2 = ls; pw2 = !ls;
    ps = fs; pw = !fs;
    for(int i=1;i<n;i++){
        bool ns = (ps && s[i] == 'o' && ps2) || (ps && s[i] == 'x' && pw2) || (pw && s[i] == 'o' && pw2) || (pw && s[i] == 'x' && ps2),
             nw = (ps && s[i] == 'o' && pw2) || (ps && s[i] == 'x' && ps2) || (pw && s[i] == 'o' && ps2) || (pw && s[i] == 'x' && pw2);
        ps2 = ps;
        pw2 = pw;
        ps = ns;
        pw = nw;
    }
    bool ok = (ls && ps) || (!ls && pw);
    prints(ok);
    vector<int> pss(n + 1), pws(n + 1);
    pss[0] = ls; pws[0] = !ls;
    pss[1] = fs; pws[1] = !fs;
    for(int i=2;i<=n;i++){
        pss[i] = (pss[i-1] && s[i-2] == 'o' && pss[i-2]) || (pss[i-1] && s[i-2] == 'x' && pws[i-2]) || (pws[i-1] && s[i-2] == 'o' && pws[i-2]) || (pws[i-1] && s[i-2] == 'x' && pss[i-2]);
        pws[i] = (pss[i-1] && s[i-2] == 'o' && pws[i-2]) || (pss[i-1] && s[i-2] == 'x' && pss[i-2]) || (pws[i-1] && s[i-2] == 'o' && pss[i-2]) || (pws[i-1] && s[i-2] == 'x' && pws[i-2]);
    }
    pss[1] &= (pss[n] && s[n-1] == 'o' && pss[n-1]) || (pss[n] && s[n-1] == 'x' && pws[n-1]) || (pws[n] && s[n-1] == 'o' && pws[n-1]) || (pws[n] && s[n-1] == 'x' && pss[n-1]);
    pws[1] &= (pss[n] && s[n-1] == 'o' && pws[n-1]) || (pss[n] && s[n-1] == 'x' && pss[n-1]) || (pws[n] && s[n-1] == 'o' && pss[n-1]) || (pws[n] && s[n-1] == 'x' && pws[n-1]);
    // bool ok2 = (ls && pss[n]) || (!ls && pws[n]);
    bool ok2 = ((ls && pss[n]) || (!ls && pws[n])) && ((fs && pss[1]) || (!fs && pws[1]));
    prints(ok2);
    prints(pss, pws);
    if(!ok2){ return; }
    for(int i=1;i<=n;i++){
        cout << (pss[i] ? 'S' : 'W');
    }
    cout << '\n';
    exit(0);
}

int main(){
    cin >> n;
    cin >> s;
    solve(false, false);
    solve(false, true);
    solve(true, false);
    solve(true, true);
    cout << -1 << '\n';
    return 0;
}