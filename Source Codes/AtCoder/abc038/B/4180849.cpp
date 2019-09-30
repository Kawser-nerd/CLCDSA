#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;

int main() {
    int H1, W1, H2, W2;
    cin >> H1 >> W1;
    cin >> H2 >> W2;
    if (H1 == W2 || H1 == H2 || W1 == W2 || W1 == H2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}