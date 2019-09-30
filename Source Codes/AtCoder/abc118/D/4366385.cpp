#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 1000000007;

Int mod_pow(Int x, Int n) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //?????(???????1???)
        x = (x * x) % MOD;
        n >>= 1; //????(n = n >> 1)
    }
    return res;
}

template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

int dp[10005];
int N;
int M;
int a[15];
int cost[15] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string ans;

int rec(int n){
    if (dp[n] != -1) return dp[n];
    int ma = -2;
    for (int i = 0; i < M; i++){
        if (n-cost[a[i]] >= 0) ma = max(ma, rec(n-cost[a[i]]));
    }
    if (ma == -2) return dp[n] = ma;
    else return dp[n] = ma+1;
}

int bt(int n){
    int ma = -2;
    for (int i = 0; i < M; i++){
        if (n-cost[a[i]] >= 0) ma = max(ma, rec(n-cost[a[i]]));
    }
    for (int i = M-1; i >= 0; i--){
        if (n-cost[a[i]] >= 0 && ma == dp[n-cost[a[i]]]){
            ans.push_back('0' + a[i]);
            bt(n-cost[a[i]]);
            break;
        }
    }
    return 0;
}

int main(){
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        cin >> a[i];
    }
    sort(a, a+M);
    bt(N);
    cout << ans << endl;

}