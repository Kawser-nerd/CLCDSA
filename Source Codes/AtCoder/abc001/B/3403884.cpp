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

int main(int argc, char **argv) {
    int m;
    cin >> m;
    if (m < 100) {
        cout << "00" << endl;
    } else if (m <= 5000) {
        cout << setfill('0') << setw(2) << m / 100 << endl;
    } else if (m <= 30000) {
        cout << setfill('0') << setw(2) << m / 1000 + 50 << endl;
    } else if (m <= 70000) {
        cout << setfill('0') << setw(2) << (m / 1000 - 30) / 5 + 80 << endl;
    } else {
        cout << 89 << endl;
    }
}