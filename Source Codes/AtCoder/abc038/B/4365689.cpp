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
    int h1,h2,w1,w2;
    cin >> h1 >> w1 >> h2 >> w2;
    if (h1 == w2 || h1 == h2 || w1 == h2 || w1 == w2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}