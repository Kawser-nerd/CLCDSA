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

const int MAXN = 1000000;
Int fact[MAXN], inv[MAXN];

Int mod_pow(Int x, Int n) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //?????(???????1???)
        x = (x * x) % MOD;
        n >>= 1; //????(n = n >> 1)
    }
    return res;
}

void init_fact() {
    fact[0] = 1;
    for(int i=1; i<MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    inv[MAXN - 1] = mod_pow(fact[MAXN - 1], MOD-2);
    for(int i=MAXN - 2; i>=0; i--) {
        inv[i] = (inv[i+1] * (i+1)) % MOD;
    }
}

Int comb(int n, int r) {
    if(r < 0 || n < r) return 0;
    return fact[n] * inv[n-r] % MOD * inv[r] % MOD;
}

template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

char field[505][505];
int flag[505][505];
int dx[] = {0, 1, 0 , -1};
int dy[] = {1, 0, -1, 0};

int dfs(int x, int y){
    flag[x][y] = 1;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (field[nx][ny] != 'x' && !flag[nx][ny]){
            dfs(nx, ny);
        }
    }
    return 0;
}

int main(){
    cin.tie(0);

    int H = 10, W = 10;
    for (int i = 0; i <= H+1; i++){
        for (int j = 0; j <= W+1; j++){
            field[i][j] = 'x';
        }
    }
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            cin >> field[i][j];
        }
    }
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            dfs(i, j);
            int ans = 1;
            for (int k = 1; k <= H; k++){
                for (int l = 1; l <= W; l++){
                    if (field[k][l] == 'o' && !flag[k][l]) ans = 0;
                }
            }
            if (ans){
                cout << "YES" << endl;
                return 0;
            }
            memset(flag, 0, sizeof(flag));
        }
    }
    cout << "NO" << endl;
    return 0;
}