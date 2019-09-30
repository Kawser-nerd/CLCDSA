#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
 
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (signed)((a).size())
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())
 
using namespace std;
 
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
 
const int MOD = 1000000007;
 
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"  << " " << __FILE__ << endl;
 
vector<int> sieve_of_eratosthenes(int n) {
    vector<int> primes(n);
    for (int i = 2; i < n; ++i)
        primes[i] = i;
    for (int i = 2; i*i < n; ++i)
        if (primes[i])
            for (int j = i*i; j < n; j+=i)
                primes[j] = 0;
    primes.erase(std::remove(primes.begin(), primes.end(), 0), primes.end());
    return primes;
}
 
signed main(void) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    VI prime = sieve_of_eratosthenes(n+1);
    VI count(prime.size(),0);
    FOR(i,2,n+1){
        int t = i;
        while(t!=1){
            for (int j = 0; j < prime.size(); ++j) {
                if(t%prime[j]==0){
                    count[j]++;
                    t/=prime[j];
                    break;
                }
            }
        }
    }
 
    int ans = 1;
    REP(i,count.size()){
        ans*=count[i]+1;
        ans%=MOD;
    }
 
    cout << ans << endl;
    
    return 0;
}