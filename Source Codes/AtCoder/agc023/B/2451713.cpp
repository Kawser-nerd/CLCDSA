#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
 
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
ll n;
char s[500][500];
char s2[500][500];
int main(){
    cin >> n;
    REP(i,n) {
        cin >> s[i];
    }

    ll ans = 0;
    REP(i,n) {
        ll A = i;ll B = 0;

        bool f = true;
        REP(j,n) {
            REP(k,n) {
                s2[j][k] = s[(j + A) % n][(k + B) % n];
            }
        }
        REP(j,n) {
            REP(k,n) {
                if(s2[j][k] != s2[k][j]) {
                    f = false;
                    break;
                }
            }
        }
        if(f) {
            ans += n;
        }
    }
    cout << ans << endl;
    return 0;
}