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

Int mod_pow(Int x, Int n){
    Int res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a;
}
Int lcm(Int a, Int b) {
    return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y) {
    Int g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

int x[100005];
int y[100005];
int c[100005];
int wcnt[1005][1005];
int bcnt[1005][1005];

int main(){
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        char co;
        cin >> x[i] >> y[i] >> co;
        if (co == 'W') c[i] = 0;
        else c[i] = 1;
        
        if (x[i]/K%2) c[i] ^= 1;
        if (y[i]/K%2) c[i] ^= 1;
        x[i] %= K;
        y[i] %= K;
        if (c[i]) bcnt[x[i]][y[i]]++;
        else wcnt[x[i]][y[i]]++;
    }
    /*cout << "debug:" << endl;
    for (int i = 0; i < N; i++){
        printf("%d %d %d\n", x[i], y[i], c[i]);
    }*/

    for (int i = 0; i < K; i++){
        for (int j = 0; j < K; j++){
            if (j) wcnt[i][j] += wcnt[i][j-1];
        }
    }

    for (int i = 0; i < K; i++){
        for (int j = 1; j < K; j++){
            wcnt[j][i] += wcnt[j-1][i];
        }
    }

    for (int i = 0; i < K; i++){
        for (int j = 0; j < K; j++){
            if (j) bcnt[i][j] += bcnt[i][j-1];
        }
    }

    for (int i = 0; i < K; i++){
        for (int j = 1; j < K; j++){
            bcnt[j][i] += bcnt[j-1][i];
        }
    }

    int ans = 0;
    for (int i = 0; i < K; i++){
        for (int j = 0; j < K; j++){
            for (int k = 0; k < 2; k++){
                int tmp = 0;
                if (k){
                    tmp += wcnt[K-1][K-1];
                    if (i-1 >= 0){ 
                        tmp -= wcnt[i-1][K-1];
                        tmp += bcnt[i-1][K-1];
                    }
                    if (j-1 >= 0){
                        tmp -= wcnt[K-1][j-1];
                        tmp += bcnt[K-1][j-1];
                    }
                    if (i-1 >= 0 && j-1 >= 0){
                        tmp += wcnt[i-1][j-1]*2;
                        tmp -= bcnt[i-1][j-1]*2;
                    }
                }else{
                    tmp += bcnt[K-1][K-1];
                    if (i-1 >= 0){ 
                        tmp -= bcnt[i-1][K-1];
                        tmp += wcnt[i-1][K-1];
                    }
                    if (j-1 >= 0){
                        tmp -= bcnt[K-1][j-1];
                        tmp += wcnt[K-1][j-1];
                    }
                    if (i-1 >= 0 && j-1 >= 0){
                        tmp += bcnt[i-1][j-1]*2;
                        tmp -= wcnt[i-1][j-1]*2;
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}