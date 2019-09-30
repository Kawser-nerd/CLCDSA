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

// ?????????
// [0,n) ???? i ?????primes[i] != 0 ? i ???
vector<int> erat(int n) {
    vector<int> primes(n);
    for (int i = 2; i < n; ++i) primes[i] = i;
    for (int i = 2; i*i < n; ++i)
        if (primes[i])
            for (int j = i*i; j < n; j+=i) primes[j] = 0;
    // ?????vector??????????????? (0 ?????????)
    // primes.erase(remove(primes.begin(), primes.end(), 0), primes.end());
    return primes;
}

int dp[55][10005][55];
int w[55];
int v[55];

int main(){
    cin.tie(0);

    int W; cin >> W;
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < 10005; j++){
            for (int k = 0; k < 55; k++){
                if (i-1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                int tmp = 0;
                if (i-1 >= 0 && j-w[i] >= 0 && k-1 >= 0){
                    tmp = dp[i-1][j-w[i]][k-1];
                }
                if (j >= w[i] && k >= 1) dp[i][j][k] = max(dp[i][j][k], v[i] + tmp);
            }
        }
    }
    cout << dp[N-1][W][K] << endl;

}