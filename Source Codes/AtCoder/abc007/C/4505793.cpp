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


char field[100][100];
int d[100][100];
queue<pair<int, int>> q;
int main(){
    cin.tie(0);

    int N, M; cin >> N >> M;
    pair<int, int> s;
    pair<int, int> g;
    int a, b; cin >> a >> b;
    s = {a, b};
    cin >> a >> b;
    g = {a, b};

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            d[i][j] = 1000000;
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cin >> field[i][j];
        }
    }

    q.push(s);
    d[s.first][s.second] = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    while (!q.empty()){
        pair<int, int> crt = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = crt.first + dx[i];
            int ny = crt.second + dy[i];
            if (field[nx][ny] == '.' && d[nx][ny] > d[crt.first][crt.second] + 1){
                q.push({nx, ny});
                d[nx][ny] = d[crt.first][crt.second] + 1;
            }
        }
    }
    cout << d[g.first][g.second] << endl;
}