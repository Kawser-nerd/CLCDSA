#include <iostream>
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
    int h[2];
    cin >> h[0] >> h[1];
    cout << h[0] - h[1] << endl;
}