#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

typedef vector<int> Vec;
typedef vector<Vec> Mat;

int m;

Mat multi(Mat a, Mat b){
    Mat c(a.size(), Vec(b[0].size()));

    rep(i, (int)a.size()){
        rep(j, (int)b[0].size()){
            rep(k, (int)b.size()){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % m) % m;
            }
        }
    }
    return c;
}

Vec multi(Mat a, Vec b){
    Vec c(a.size());

    rep(i, (int)a.size()){
        rep(j, (int)b.size()){
            c[i] = (c[i] + a[i][j] * b[j] % m) % m;
        }
    }
    return c;
}

Mat powMat(Mat a, int n){
    Mat b(a.size(), Vec(a[0].size()));;
    rep(i, (int)a.size()){
        rep(j, (int)a[0].size()){
            if(i == j){
                b[i][j] = 1;
            }
        }
    }

    while(n != 0){
        if(n % 2 == 1){
            b = multi(b, a);
        }

        n /= 2;
        a = multi(a, a);
    }
    return b;
}

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % m, n / 2);
    }
    return powM(x, n-1) * x % m;
}

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }

    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

signed main(){
    int a, b;
    cin >> a >> b >> m;

    int d = gcd(a, b);

    Vec e = {1, 1};
    Mat ma(2, Vec(2));
    ma[0][0] = 10;
    ma[0][1] = 1;
    ma[1][0] = 0;
    ma[1][1] = 1;

    Vec va = multi(powMat(ma, a-1), e);

    Mat mb(2, Vec(2));
    mb[0][0] = powM(10, d);
    mb[0][1] = 1;
    mb[1][0] = 0;
    mb[1][1] = 1;

    Vec vb = multi(powMat(mb, b / d - 1), e);

    cout << va[0] * vb[0] % m << endl;

    return 0;
}