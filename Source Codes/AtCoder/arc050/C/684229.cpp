#include <iostream>
#include <vector>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
typedef long long ll;
using namespace std;
ll gcd(ll a, ll b) { if (b < a) swap(a,b); while (a) { ll c = a; a = b % c; b = c; } return b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll powi(ll x, ll y, ll p) { x = (x % p + p) % p; ll z = 1; for (ll i = 1; i <= y; i <<= 1) { if (y & i) z = z * x % p; x = x * x % p; } return z; }
ll inv(ll x, ll p) { assert ((x % p + p) % p != 0); return powi(x, p-2, p); }

ll a, b, m; // global

vector<vector<ll> > operator * (vector<vector<ll> > const & p, vector<vector<ll> > const & q) { int n = p.size(); vector<vector<ll> > r(n, vector<ll>(n)); repeat (y,n) { repeat (z,n) { repeat (x,n) { r[y][x] += p[y][z] * q[z][x] % m; r[y][x] %= m; } } } return r; }
vector<ll> operator * (vector<vector<ll> > const & p, vector<ll> const & q) { int n = p.size(); vector<ll> r(n); repeat (y,n) { repeat (z,n) { r[y] += p[y][z] * q[z] % m; r[y] %= m; } } return r; }
vector<vector<ll> > unit_matrix(int n) { vector<vector<ll> > e(n, vector<ll>(n)); repeat (i,n) e[i][i] = 1; return e; }
vector<vector<ll> > mul (vector<vector<ll> > const & p, vector<vector<ll> > const & q) { return p * q; }
template <typename T, typename F> T powt(T x, ll y, T unit, F f) { T z = unit; for (ll i = 1; i <= y; i <<= 1) { if (y & i) z = f(z, x); x = f(x, x); } return z; }

int main() {
    cin >> a >> b >> m;
    ll d = gcd(a, b);
    vector<vector<ll> > f(2, vector<ll>(2));
    vector<vector<ll> > g(2, vector<ll>(2));
    vector<ll> e(2);
    f[0][0] = 10; f[0][1] = 1;
    f[1][0] =  0; f[1][1] = 1;
    g[0][0] = powi(10,d,m); g[0][1] = 1;
    g[1][0] =            0; g[1][1] = 1;
    e[0] = 0;
    e[1] = 1;
    a = (powt(f,   a, unit_matrix(2), &mul) * e)[0];
    b = (powt(g, b/d, unit_matrix(2), &mul) * e)[0];
    cout << a * b % m << endl;
    return 0;
}