#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <time.h>
#include <memory>
using namespace std;

typedef long long LL;
typedef long long uLL;
typedef unsigned int uint;
#define FOR(i, b, e) for(int i=(b); i<int(e); ++i)
#define FORV(i, b, e) for(i=(b); i<(e); ++i)
#define GET(a) cin >> a
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PB(a) push_back(a)
#define SIZE(a) a.size()
#define PEEK(a) cout << " >> " #a " = " << a << endl
#define peek(a) _peek(#a, a)
template <typename T> void _peek(char name[], T &obj, size_t max_count=32){
    const size_t ipl = 10;
    cout << " >> " << name << " = ["; size_t _count = 0;
    for(typename T::iterator it=obj.begin(); it!=obj.end(); ++it){
        if(_count && _count%ipl == 0) cout << "      [";
        cout << *it; ++_count;
        if(_count%ipl == 0 || _count >= max_count || it == obj.end()-1) cout << " ]\n";
        else cout << ", ";
        if(_count >= max_count) break;
    }
}
template <typename T> ostream &operator << (ostream &cout, pair<T, T> &x){
    cout << "(" << x.first << "," << x.second << ")";
    return cout;
}
template <typename T> inline T GCD(T a, T b){
    if(b==0) return a;
    a %= b; while(a){ swap(a, b); a %= b; }; return b;
}
template <typename T> inline T LCM(T a, T b){
    if(a == 0 || b == 0) return -1;
    a /= GCD(a, b);	T lcm = a * b;
    if(lcm < 0 || lcm/a != b ) return -1;
    return lcm;
}
//===========================================================
int T, test_case;
int N, S;
int P;
int t[200];

uint solve(){
    int ans=0; int extra = 0;
    FOR(i, 0, N){
        if(t[i] >= 3*P-2) ++ans;
        else if(P>=2 && t[i] >= 3*P-4) ++extra;
    }

    ans += min(extra, S);
    return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
    //freopen("z:\\input.txt", "r", stdin);
    freopen("z:\\output.txt", "w", stdout);
    freopen("z:\\B-large.in", "r", stdin);


    //srand(time(0)^132474);


    cin >> T;
    FORV(test_case, 1, T+1)
    {
        cin >> N >> S >> P;
        FOR(i, 0, N) cin >> t[i];
        cout << "Case #" << test_case << ": " << solve() <<endl;
    }

    return 0;
}

