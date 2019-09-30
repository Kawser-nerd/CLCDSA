#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

#define FOR(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)

using namespace std;
long long MOD = 1;
typedef vector<vector<long long>> Matrix;
Matrix product(Matrix &x1,
    Matrix &x2) {
    int row = x1.size();
    int col = x2[0].size();
    int inter = x1[0].size();
    Matrix mat(row, vector<long long>(col, 0));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            for (int k = 0; k < inter; k++)
                mat[i][j] = (mat[i][j] + ((x1[i][k] % MOD) * (x2[k][j] % MOD)) % MOD) % MOD;

    return mat;
}

Matrix power(Matrix &x, long long p) {
    int n = x.size();
    Matrix mat(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        mat[i][i] = 1;

    if (p == 0)
        return mat;
    if (p == 1)
        return x;

    mat = power(x, p / 2);
    mat = product(mat, mat);
    if (p % 2 == 0)
        return mat;
    else
        return product(mat, x);
}

long long power(long long n, long long p) {
    if (p == 0)
        return 1;
    long long res = 1;
    long long add = n;
    while (p > 0) {
        if (p & 1)
            res = (res * add) % MOD;
        p >>= 1;
        add = add*add%MOD;
    }
    return res;
}

long long gcd(long long a, long long b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main() {
    long long a, b, m;
    cin >> a >> b >> m;
    MOD = m;
    long long g = gcd(a, b);

    long long num = b / g;
    Matrix x = { {10,1},{0,1} };
    Matrix y = { {power(10, g), 1}, {0, 1} };
    x = power(x, a - 1);
    y = power(y, num - 1);

    long long res1 = x[0][0] + x[0][1], res2 = y[0][0] + y[0][1];
    cout << ((res1%MOD) * (res2%MOD)) % MOD << endl;


    return 0;
}