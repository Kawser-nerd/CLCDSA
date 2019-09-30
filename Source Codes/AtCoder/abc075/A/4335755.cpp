#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <set>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if (a != b && b != c) {
        cout << b << endl;
    } else if (a != b && a != c) {
        cout << a << endl;
    } else {
        cout << c << endl;
    }

    return 0;
}