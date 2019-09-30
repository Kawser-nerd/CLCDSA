#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forit(i, v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

bool isv(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

li get2(string s, int n){

    li ans = 0;

    forn(i, sz(s)){
        int cur = 0, maxv = 0;
        fore(j, i, sz(s)){
            if(isv(s[j]))
                cur = 0;
            else
                cur++;
            maxv = max(maxv, cur);

            if(maxv >= n)
                ans++;
        }
    }

    return ans;
}

li get(string s, int n){
    vector<int> d(sz(s) + 1), cur(sz(s) + 1);
    d[sz(s)] = -1, cur[sz(s)] = 0;
    ford(i, sz(s)){
        if(!isv(s[i]))
            cur[i] = cur[i + 1] + 1;

        if(cur[i] >= n)
            d[i] = i + n;
        else
            d[i] = d[i + 1];
    }

    li ans = 0;
    forn(i, sz(s)){
        if(d[i] != -1)
            ans += sz(s) - d[i] + 1;
    }
    return ans;
}


int main() {
    #ifdef myproject
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    #endif

    int tests;
    cin >> tests;
    forn(testsit, tests){
        printf("Case #%d: ", testsit+1);

        string s; int n;
        cin >> s >> n;

        cout << get(s, n);

        /*
        if(get(s, n) != get2(s, n)){
            cerr << s << " " << n << endl;
            throw;
        }*/

        puts("");
        //cerr << "testsit=" << testsit+1 << " " << clock() << endl;
    }
    return 0;
}


