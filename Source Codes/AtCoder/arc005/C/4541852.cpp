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

struct Edge{
    int from, to, cost;
};


template <typename T>
vector<T> dijkstra(vector<vector<Edge>> &G, int s) {
    int V = G.size();
    vector<T> d(V); fill(d.begin(), d.end(), numeric_limits<T>::max());
    priority_queue<pair<T, int> , vector< pair<T, int> >, greater< pair<T, int> > > que;
    d[s] = 0;
    que.push(make_pair(0,s));

    while(!que.empty()) {
        pair<T, int> p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<G[v].size(); i++) {
            Edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
        }
    }
    return d;
}

char field[505][505];

vector<vector<Edge>> G;
int goal;
int start;

int main(){
    cin.tie(0);

    int H, W; cin >> H >> W;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> field[i][j];
            if (field[i][j] == 'g') goal = i*W+j;
            if (field[i][j] == 's') start = i*W+j;
        }
    }
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    G = vector<vector<Edge>>(H*W);
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            for (int k = 0; k < 4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (nx >= W || ny >= H) continue;
                if (nx < 0 || ny < 0) continue;
                if (field[ny][nx] == '#'){
                    Edge e = {i*W+j, ny*W+nx, 1};
                    G[i*W+j].push_back(e);
                }else{
                    Edge e = {i*W+j, ny*W+nx, 0};
                    G[i*W+j].push_back(e);
                }
            }
        }
    }

    vector<int> d = dijkstra<int>(G, start);
    if (d[goal] <= 2) cout << "YES" << endl;
    else cout << "NO" << endl; 
}