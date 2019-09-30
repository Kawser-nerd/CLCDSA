#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<climits> //INT_MIN/MAX
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
 
/* -----  xtimex  Problem: ABC 0 ABCD / Link:  ----- */
/* ------???---
 
 
 
-----??????----- */
/* -----???-----
 
 
 
----??????---- */
 
ll N, A, B;
ll v[60];
ll ans = 0;
ll comb[100][100];
 
double ave = 0;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    cin >> N >> A >> B;
    FOR(i, 0, N) {
        cin >> v[i];
    }
 
 
    for (int i = 0; i <= 60; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                comb[i][j] = 1;
            else
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
 
 
    sort(v, v + N);
    reverse(v, v + N);
 
    if (v[0] != v[A - 1]) {
        int cnt = 0, ne = 0;
        FOR(i, 0, N) {
            if (v[A - 1] == v[i]) {
                cnt++;
                if (i < A) {
                    ne++;
                }
            }
            if (i < A)ave += v[i];
        }
        //debug(cnt);
        ave /= A;
        ans = comb[cnt][ne];
    }
    else if (v[0] == v[A - 1]) {
        int cnt = 0;
        FOR(i, 0, N) {
            if (v[0] == v[i])cnt++;
        }
        ave = v[0];
        FOR(i, A, B + 1) {
            if (cnt>=i) {
                ans += comb[cnt][i];
            }
        }
 
    }
 
    printf("%.10f\n", ave);
    cout << ans << endl;
    return 0;
}