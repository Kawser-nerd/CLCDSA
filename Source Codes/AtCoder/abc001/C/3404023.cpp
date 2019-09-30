#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

#ifdef GCD_LCM
ll gcd(ll a,ll b) {
    if(b <= 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b) {
    return (a * b) / gcd(a,b);
}
#endif
char dw[16][4] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW",
                  "WSW", "W", "WNW", "NW", "NNW"};
int dg[] = {1125, 3375, 5625, 7875, 10125, 12375, 14625, 16875, 19125, 21375, 23625, 25875, 28125,
            30375, 32625,34875};
int wp[] = {25, 155, 335, 545, 795, 1075, 1385, 1715, 2075, 2445, 2845, 3265};

int main(int argc, char **argv) {
    int deg, dis;
    cin >> deg >> dis;
    deg = deg * 10;
    dis = dis * 10;
    int w = 0, p = 0;
    for (int i = 0; i < 16; i++) {
        if (dg[i] <= deg) {
            w = i + 1;
        }
    }
    
    for (int i = 0; i < 12; i++) {
        if (wp[i] * 6 <= dis) {
            p = i + 1;
        }
    }
    if (p)
        cout << dw[w%16] << " " << p << endl;
    else
        cout << "C 0" << endl;
}