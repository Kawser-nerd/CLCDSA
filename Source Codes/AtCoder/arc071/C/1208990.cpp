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
    string s, t;
    cin >> s >> t;
    vector<int> accs(s.size()), acct(t.size());
    for(int i=0;i<s.size();i++){
        accs[i] = (i - 1 >= 0 ? accs[i - 1] : 0) + (s[i] == 'A' ? 1 : -1);
    }
    for(int i=0;i<t.size();i++){
        acct[i] = (i - 1 >= 0 ? acct[i - 1] : 0) + (t[i] == 'A' ? 1 : -1);
    }
    int q; cin >> q;
    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        int n1 = 0, n2 = 0;
        // for(int j=a;j<=b;j++){
        //     n1 += s[j] == 'A' ? 1 : -1;
        // }
        // for(int j=c;j<=d;j++){
        //     n2 += t[j] == 'A' ? 1 : -1;
        // }
        n1 = accs[b] - (a - 1 >= 0 ? accs[a - 1] : 0);
        n2 = acct[d] - (c - 1 >= 0 ? acct[c - 1] : 0);
        n1 = (n1 + 3 * 100000) % 3;
        n2 = (n2 + 3 * 100000) % 3;
        cout << (n1 == n2 ? "YES" : "NO") << '\n';
    }
    return 0;
}