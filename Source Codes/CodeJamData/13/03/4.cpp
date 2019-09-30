//Coder: Balajiganapathi

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros

#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define fr(i,n)     re(i,0,n)
#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const ll upto = ll(1e18);
const int mx = 10000007;

int cnt;
string num[mx];
const int dmax = 100;
int dig[2 * dmax + 5], d;

bool compare(string a, string b) {
    if(sz(a) != sz(b)) return sz(a) < sz(b);
    return a < b;
}

string buildEven() {
    int c = 2 * d;
    fr(i, d) dig[c - 1 - i] = dig[i];
    string ret(2 * c - 1, '0');
    fr(i, c) fr(j, c) ret[i + j] += dig[i] * dig[j];
    
    return ret;
}

string buildOdd() {
    int c = 2 * d - 1;
    fr(i, d - 1) dig[c - 1 - i] = dig[i];
    string ret(2 * c - 1, '0');
    fr(i, c) fr(j, c) ret[i + j] += dig[i] * dig[j];
    
    return ret;
}

void calcEven(int sum = 0) {
    if(2 * (2 * d) - 1 > dmax || sum >= 10) return;
    if(d && sum == 0) return;
    if(d) num[cnt++] = buildEven();
    
    fr(i, 10) {
        dig[d++] = i;
        calcEven(sum + 2 * i * i);
        --d;
    }
}

void calcOdd(int sum = 0, int last = 0) {
    if(2 * (2 * d - 1) - 1 > dmax || sum >= 10) return;
    if(d && sum == 0) return;
    //cerr << sum << " " << last << endl;
    if(d) num[cnt++] = buildOdd();
    fr(i, 10) {
        dig[d++] = i;
        calcOdd(sum + last * last + i * i, i);
        --d;
    }
}

void calc() {
    calcEven();
    calcOdd();
    sort(num, num + cnt, compare);
    cerr << cnt << endl;
    //fr(i, cnt) cout << num[i] << endl;
}


int main() {
    //freopen("sample.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen("C-small-attempt0.in", "r", stdin); freopen("small0.txt", "w", stdout);
    //freopen("C-large-1.in", "r", stdin); freopen("large1_check.txt", "w", stdout);
    freopen("C-large-2.in", "r", stdin); freopen("large2.txt", "w", stdout);
    //freopen("till18.txt", "w", stderr);
    
    calc();
    //return 0;
    int _T;
    scanf("%d", &_T);
    for(int _t = 1; _t <= _T; ++_t) {
        string a, b;
        cin >> a >> b;
        int ans = upper_bound(num, num + cnt, b, compare) - lower_bound(num, num + cnt, a, compare);
        printf("Case #%d: %d\n", _t, ans);
    }

	return 0;
}
