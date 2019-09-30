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


int dp[41][401][401];
int a[41];
int b[41];
int c[41];

int main(){
    cin.tie(0);

    int N, Ma, Mb; cin >> N >> Ma >> Mb;
    for (int i = 0; i < N; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    int INF = 100000000;
    fill(dp[0][0], dp[41][0], INF);
    dp[0][0][0] = 0;
    for (int i = 1; i <= 40; i++){
        for (int j = 0; j < 401; j++){
            for (int k = 0; k < 401; k++){
                if (dp[i-1][j][k] == INF) continue;
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
                if (j + a[i-1] <= 400 && k + b[i-1] <= 400){
                    dp[i][j+a[i-1]][k+b[i-1]] = min(dp[i][j+a[i-1]][k+b[i-1]], dp[i-1][j][k] + c[i-1]); 
                }     
            }
        }
    }
    int ans = INF;
    for (int j = 1; j < 401; j++){
        for (int k = 1; k < 401; k++){
            if (j*Mb == k*Ma){
                ans = min(ans, dp[N][j][k]);
            }                 
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}