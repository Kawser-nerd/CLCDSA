#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }

typedef long long  ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int dp[110][4][4][4];
int main() {
    int N;
    cin>>N;
    int mod=1e9+7;
    dp[0][3][3][3]=1;
    REP(i,N){
        REP(j,4){
            REP(k,4){
                REP(l,4){
                    if(dp[i][j][k][l]==0) continue;
                    REP(a,4){
                        if(a==2 && j==1 && k==0) continue;
                        if(a==2 && j==0 && k==1) continue;
                        if(a==1 && j==2 && k==0) continue;
                        if(a==2 && k==1 && l==0) continue;
                        if(a==2 && j==1 && l==0) continue;
                        dp[i+1][a][j][k]+=dp[i][j][k][l];
                        dp[i+1][a][j][k]%=mod;
                    }
                }
            }
        }
    }
    int ans=0;
        REP(j,4){
            REP(k,4){
                REP(l,4){
                    ans+=dp[N][j][k][l];
                    ans%=mod;
                }
                }
                }
    cout<<ans<<endl;

    return 0;
}