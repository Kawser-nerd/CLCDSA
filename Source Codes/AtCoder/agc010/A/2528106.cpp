#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define np(v) next_permutation(v.begin(), v.end())
#define pll pair < long long, long long>
#define all(a) a.begin(), a.end()
#define ull unsigned long long
#define pii pair < int, int >
#define sz(a) (int)a.size()
#define sqr(x) ((x) * (x))
#define y1 stupid_cmath
#define vi vector <int>
#define pb push_back
#define mp make_pair
#define ll long long
#define endl "\n"
#define s second
#define f first


const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const int N = (int)50505;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, x;

void solve(){
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        if(x & 1) cnt++;
    }
    if(n == 1){
        cout << "YES" << endl;
        return ;
    }
    if(cnt & 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T;
//    cin >> T;
    T = 1;
    for(int i = 1; i <= T; ++i){
        solve();
    }
}