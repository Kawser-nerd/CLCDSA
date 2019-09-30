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

Int dp[105][10];

Int amidas[10][10];

int main(){
    cin.tie(0);
    
    Int H, W, K; cin >> H >> W >> K;
    K--;

    dp[0][0] = 1;

    for (int i = 0; i < (1 << (W-1)); i++){
        int flag = 1;
        for (int j = 0; j < W-2; j++){
            if (i & (1 << j) && i & (1 << (j+1))) flag = 0;
        }
        if (!flag) continue;

        int amida[10];
        for (int j = 0; j < W; j++){
            amida[j] = j;
        }

        for (int j = 0; j < W-1; j++){
            if ((1 << j) & i){
                swap(amida[j], amida[j+1]);
            }
        }

        for (int j = 0; j < W; j++){
            amidas[amida[j]][j]++;
        }
    }

    for(int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            dp[i+1][j] += dp[i][j] * amidas[j][j] % MOD;
            dp[i+1][j] %= MOD;

            if (j-1 >= 0){
                dp[i+1][j-1] += dp[i][j] * amidas[j][j-1] % MOD;
                dp[i+1][j-1] %= MOD;
            }

            if (j+1 < W){
                dp[i+1][j+1] += dp[i][j] * amidas[j][j+1] % MOD;
                dp[i+1][j+1] %= MOD;
            }
        }
    }

    cout << dp[H][K] << endl;
    return 0;
}