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
typedef vector<int> vec;
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
int _rank(mat A, int n)
{
    int i, j, k;
    rep(i, n)
    {
        int be = i, mi = n + 1;
        for (j = i; j < n; j++) {
            rep(k, n) if (A[j][k]) break;
            if (k < mi)
                be = j, mi = k;
        }
        if (mi >= n)
            break;
        rep(j, n)
            swap(A[i][j], A[be][j]);

        rep(j, n) if (i != j && A[j][mi])
        {
            rep(k, n)
                A[j][k]
                ^= A[i][k];
        }
    }
    return i;
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
mat mul_mat_mod(mat A, mat B, lli m)
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
mat pow_mat(mat A, lli p, lli mod)
{
    int n = A.size();
    mat B = mat(n, vec(n));
    while (p > 0) {
        if (p & 1) {
            B = mul_mat_mod(A, B, mod);
        }
        A = mul_mat_mod(A, A, mod);
        p >>= 1;
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
int det(mat A)
{
    const int n = A.size();
    int D = 1;
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j)
            if (abs(A[j][i]) > abs(A[pivot][i]))
                pivot = j;
        swap(A[pivot], A[i]);
        D &= A[i][i];
        if (abs(A[i][i]) < eps)
            break;
        for (int j = i + 1; j < n; ++j)
            for (int k = n - 1; k >= i; --k)
                A[j][k] ^= A[i][k] & A[j][i];
    }
    return D;
}

int main()
{
    // rep(i, 300) rep(j, 300)
    // {
    //     if (j % 3 == 0)
    //         cout << '0';
    //     else
    //         cout << '1';
    //     if (j == 299)
    //         cout << endl;
    // }
    int n;
    cin >> n;
    mat m = mat(n, vec(n));
    char c;
    rep(i, n) rep(j, n)
    {
        cin >> c;
        m[i][j] = (int)(c - '0');
    }
    int a = det(m);
    if (a & 1)
        cout << "Odd" << endl;
    else
        cout << "Even" << endl;
} ./Main.cpp:50:1: warning: control reaches end of non-void function [-Wreturn-type]
}
^
1 warning generated.