#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <cassert>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define ALL(a) (a).begin(),(a).end()

#define pb push_back

using namespace std;
typedef unsigned long ul;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;

int main() {
    ll dp[100001];
    int n; cin >> n;
    int a[n];
    REP(i,n){
        dp[i] = 0;
        cin >> a[i];
    }
    int t = 0;
    dp[0] = 1;
    FOR(i,1,n){
        if (a[i-1] < a[i]){
            dp[i] = dp[i-1]+(i-t+1);
        } else {
            dp[i] = dp[i-1]+1;
            t = i;
        }
    }
    cout << dp[n-1] << endl;
}