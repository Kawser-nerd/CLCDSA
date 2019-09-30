#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;

const int MAX_N = 1000000;
typedef vector<int> vec;
typedef vector<vec> mat;

// ---------------------------------
mat mul(mat &A, mat &B, ll M){
    mat C(A.size(), vec(B[0].size()));

    rep(i, A.size())
        rep(k, B.size())
            rep(j, B[0].size())
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
            }
    return C;
}

// A : n*n matrix
// A ** n
mat pow(mat A, ll n, ll M){
    mat B(A.size(), vec(A.size()));
    rep(i, A.size()){B[i][i] = 1;}

    while(n > 0){
        if(n & 1){B = mul(B, A, M);}
        A = mul(A, A, M);
        n >>= 1;
    }
    return B;
}

// A : n*n matrix
// (A ** k , Sk) = ((A O I I) ** k) * ((I O))
// Sk = I + A + A ** 2 + .. A ** (k-1)
// S0 = 0, S1 = 1
mat powsum(mat A, ll k, ll M){
    int n = A.size();

    mat B(n * 2, vec(n * 2));

    rep(i, n) rep(j, n) {B[i][j] = A[i][j];} // UpLeft   A
    rep(i, n) {B[n+i][i] = 1;} // DownLeft I
    rep(i, n) {B[n+i][n+i] = 1;} // DownRight I

    B = pow(B, k, M);

    mat R(n, vec(n));
    rep(i, n) rep(j, n){
            R[i][j] = B[n + i][j]; // DownLeft
        }
    return R;
}

// 1 + A + A ** 2 + .. A ** (k-1)
ll powval(ll A, ll n, ll M){
    mat X(1, vec(1));
    X[0][0] = A;
    return pow(X, n, M)[0][0];
}

// 1 + A + A ** 2 + .. A ** (k-1)
ll powsumval(ll A, ll k, ll M){
    mat X(1, vec(1));
    X[0][0] = A;
    return powsum(X, k, M)[0][0];
}

// ---------------------------------

ll A, B, M;
ll D[50];

ll gcd1(ll a, ll b) {
    return b == 0 ? a : gcd1(b, a % b);
}

int main() {
    cin >> A >> B >> M;
    ll g = gcd1(A, B);
    // (f(A) / f(g)) * f(B)

    ll a = A / g;
    // 1 + (10^g) + ... + (10^g)^(a-1)
    ll aa = powsumval(powval(10, g, M), a, M);

    // 1 + 10 + ... + 10^(B-1)
    ll bb = powsumval(10, B, M);
    cout << (aa * bb) % M << endl;

}