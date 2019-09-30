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
Int amida[10][10];

int main(){
    cin.tie(0);

    Int H, W, K; cin >> H >> W >> K;

    dp[0][0] = 1;

    for (int i = 0; i < (1 << (W-1)); i++){
        int flag = 1;
        for (int j = 0; j < (W-2); j++){
            if ((1 << j) & i && (1 << (j+1)) & i){
                flag = 0;
            }
        }
        if (!flag) continue;

        int pos[10];
        for (int j = 0; j < W; j++){
            pos[j] = j;
        }

        for (int j = 0; j < (W-1); j++){
            if ((1 << j) & i) swap(pos[j], pos[j+1]);
        }

        for (int j = 0; j < W; j++){
            amida[pos[j]][j]++;
        }
    }

    for (int h = 1; h <= H; h++){
        for (int w = 0; w < W; w++){
            if (w-1 >= 0) dp[h][w] += dp[h-1][w-1] * amida[w-1][w] % MOD;
            dp[h][w] %= MOD;
            dp[h][w] += dp[h-1][w] * amida[w][w] % MOD;
            dp[h][w] %= MOD;
            if (w+1 < W) dp[h][w] += dp[h-1][w+1] * amida[w+1][w] % MOD;
            dp[h][w] %= MOD;
        }
    }
    cout << dp[H][K-1] << endl;
    
}