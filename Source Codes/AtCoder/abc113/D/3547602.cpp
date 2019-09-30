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

int main(){
    cin.tie(0);
    
    Int H, W, K; cin >> H >> W >> K;
    K--;

    dp[0][0] = 1;
    for(int i = 0; i < H; i++){
        int lim = (1 << (W-1));
        for (int j = 0; j < lim; j++){
            int flag = 1;
            for (int k = 0; k < (W-2); k++){
                if ((1 << k) & j && (1 << (k+1)) & j){
                    flag = 0;
                }
            }
            if (!flag) continue;

            int amida[10];
            for (int k = 0; k < W; k++){
                amida[k] = k;
            }

            for (int k = 0; k < (W-1); k++){
                if ((1 << k) & j){
                    swap(amida[k], amida[k+1]);
                }
            }

            for (int k = 0; k < W; k++){
                dp[i+1][k] += dp[i][amida[k]];
                dp[i+1][k] %= MOD;
            }
        }
    }

    cout << dp[H][K] << endl;
    return 0;
}