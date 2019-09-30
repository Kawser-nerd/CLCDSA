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


int main() {
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < W + 2; ++ i) {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        cout << "#" << s << "#" << endl;
    }
    for (int i = 0; i < W + 2; ++ i) {
        cout << "#";
    }
    cout << endl;
}