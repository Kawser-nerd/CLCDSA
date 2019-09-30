#include "math.h"
#include <algorithm>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define ifor(i, a, b) for (int i = (a); i < (b); i++)
#define rfor(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long double ld;
typedef long long int lli;
typedef complex<double> P;
const double eps = 1e-11;
int vex[4] = {1, 0, -1, 0};
int vey[4] = {0, 1, 0, -1};
typedef vector<double> Vec;
typedef vector<lli> vec;
typedef vector<Vec> MAT;
typedef vector<vec> mat;
lli MOD = 1000000007;
//Ax=b???A?????
//rankA<=min(m,n)???????vec???


/*c++11?????
for (auto itr = data.begin(); itr != data.end(); ++itr) {
        ans = ans * (itr->second + 1) % MOD;
    }*/
map<lli, lli> primeBunaki(lli m)
{

    map<lli, lli> data;
    int a = 2;
    while (m >= a * a) {
        if (m % a == 0) {
            data[a]++;
            m /= a;
        } else {
            a++;
        }
    }
    data[m]++;
    return data;
}

Vec gauss_jordan(const MAT& A, const Vec& b)
{
    int n = A.size();
    MAT B(n, Vec(n + 1));
    rep(i, n) rep(j, n) B[i][j] = A[i][j];
    rep(i, n) B[i][n] = b[i];

    rep(i, n)
    {
        int pivot = i;
        for (int j = i; j < n; j++) {
            if (abs(B[j][i]) > abs(B[pivot][i]))
                pivot = j;
        }

        swap(B[i], B[pivot]);
        if (abs(B[i][i]) < eps)
            return Vec();
        //B_i_i???0?????????
        for (int j = i + 1; j <= n; j++)
            B[i][j] /= B[i][i];
        rep(j, n)
        {
            if (i != j)
                for (int k = i + 1; k <= n; k++) {
                    B[j][k] -= B[j][i] * B[i][k];
                }
        }
    }
    Vec x(n);
    for (int i = 0; i < n; i++) {
        x[i] = B[i][n];
    }
    return x;
}
double det(const MAT& A)
{
    int n = A.size();
    MAT B(n, Vec(n));
    rep(i, n) rep(j, n) B[i][j] = A[i][j];
    double ans = 1;
    rep(i, n)
    {
        int pivot = i;
        for (int j = i; j < n; j++) {
            if (abs(B[j][i]) > abs(B[pivot][i]))
                pivot = j;
        }
        if (i != pivot)
            ans *= -1;
        swap(B[i], B[pivot]);
        if (abs(B[i][i]) < eps)
            return 0;
        ans *= B[i][i];
        for (int j = i + 1; j < n; j++)
            B[i][j] /= B[i][i];
        rep(j, n)
        {
            if (i != j)
                for (int k = i + 1; k < n; k++) {
                    B[j][k] -= B[j][i] * B[i][k];
                }
        }
    }
    return ans;
}

int rank(const MAT& A)
{
    int n = A.size();
    MAT B(n, Vec(n));
    rep(i, n) rep(j, n) B[i][j] = A[i][j];

    rep(i, n)
    {
        int pivot = i;
        for (int j = i; j < n; j++) {
            if (abs(B[j][i]) > abs(B[pivot][i]))
                pivot = j;
        }
        swap(B[i], B[pivot]);
        if (abs(B[i][i]) < eps)
            return i;
        for (int j = i + 1; j < n; j++)
            B[i][j] /= B[i][i];
        rep(j, n)
        {
            if (i != j)
                for (int k = i + 1; k < n; k++) {
                    B[j][k] -= B[j][i] * B[i][k];
                }
        }
    }
    return n;
}
lli euler(lli m)
{
    vector<int> p;
    lli M = m;
    for (int i = 2; i <= m; i++) {
        if (m % i == 0) {
            p.push_back(i);
            while (m % i == 0)
                m /= i;
        }
        if (M < i * i && p.size() == 0) {
            p.push_back(M);
            break;
        }
    }
    lli ans = M;
    rep(i, p.size())
    {
        //cout << p[i]<<endl;
        ans = ans * (p[i] - 1) / p[i];
    }
    return ans;
}
lli powm(lli a, lli p, lli mod)
{
    lli ans = 1;
    while (p > 0) {
        if (p & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        p >>= 1;
    }
    return ans % mod;
}
lli inv(lli a, lli mod)
{
    return powm(a, euler(mod) - 1, mod);
}
lli inv(lli a)
{
    return powm(a, MOD - 2, MOD);
}
lli gcd(lli A, lli B)
{
    if (A % B == 0)
        return B;
    else
        return gcd(B, A % B);
}
mat mul_mat_mod(mat& A, mat& B, lli m)
{
    int n = A.size();
    mat C(n, vec(n));
    rep(i, n) rep(j, n) rep(k, n)
    {
        C[i][j] += A[i][k] * B[k][j] % m;
        C[i][j] %= m;
    }
    return C;
}
mat En(int n)
{
    mat A = mat(n, vec(n));
    rep(i, n) A[i][i] = 1;
    return A;
}
vec mul_mat_vec(mat& A, vec& B, lli m)
{
    int n = A.size();
    vec C(n);
    rep(i, n)
    {
        rep(j, A[0].size())
        {
            C[i] += A[i][j] * B[j];
        }
    }
    return C;
}
void show_mat(mat A)
{
    int w = A[0].size();
    int h = A.size();
    rep(i, h) rep(j, w)
    {
        cout << A[i][j] << ' ';
        if (j == w - 1)
            cout << endl;
    }
}
mat pow_mat(mat& A, lli p, lli mod)
{
    int n = A.size();
    mat B = mat(n, vec(n));
    rep(i, n) B[i][i] = 1;
    while (p > 0) {
        if (p & 1) {
            B = mul_mat_mod(A, B, mod);
        }
        A = mul_mat_mod(A, A, mod);
        p /= 2;
    }
    return B;
}
lli comb(lli a, lli b)
{
    lli ans = 1;
    rep(i, b)
    {
        ans = ans % MOD * (a - i) % MOD * inv(b - i) % MOD;
    }
    return ans;
}
int near(double a)
{
    int b = (int)a;
    if (a - b > 0.5)
        b++;
    return b;
}
mat a = mat(2, vec(2));
mat b = mat(2, vec(2));
mat c = mat(2, vec(2));
mat d = mat(2, vec(2));
int main()
{
    lli A, B, M;
    cin >> A >> B >> M;
    a[0][0] = 10;
    a[0][1] = 1;
    a[1][1] = 1;
    a[1][0] = 0;
    b[0][0] = powm(10, gcd(A, B), M);
    b[0][1] = 1;
    b[1][1] = 1;
    b[1][0] = 0;
    c = pow_mat(a, A - 1, M);
    d = pow_mat(b, B / gcd(A, B) - 1, M);
    lli ans = (c[0][0] + c[0][1]) % M * (d[0][0] + d[0][1]) % M;
    cout << (ans + M) % M << endl;
}