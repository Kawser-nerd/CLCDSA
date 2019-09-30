#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

using P = array<int, 2>;
using R = long double;
using Pc = complex<R>;
const R pi = acos(R(-1));
const R EPS = 1e-12;

int N;
R rad;

R getA(R d) {
    return asin(rad/d);
}

int dfs(P l, P r, R lar, R rar) {
//    printf("(%d %d) (%d %d) %Lf %Lf\n", l[0], l[1], r[0], r[1], lar, rar);
    if (rar <= lar+EPS) return 0;
    P myP = P{l[0]+r[0], l[1]+r[1]};
    Pc my = Pc(myP[0], myP[1]);
    if (N <= max(myP[0], myP[1])) return 0;
    R myar = arg(my);
    R ardi = getA(abs(my));
    R ardown = myar-ardi, arup = myar+ardi;
//    cout << ardi << endl;
//    printf("%Lf %Lf\n", ardown, arup);
    int ans = 0;
    if (!(rar <= ardown or arup <= lar)) ans++;
    ans += dfs(l, myP, lar, ardown);//, ardown));
    ans += dfs(myP, r, arup, rar);
    return ans;
}

void solve() {
    cin >> N >> rad;
    rad /= 1000000;
//    cout << getA(1) << " " << arg(Pc(1, rad)) << endl;
    cout << 2+dfs(P{1, 0}, P{0, 1}, getA(1), pi/2-getA(1)) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}