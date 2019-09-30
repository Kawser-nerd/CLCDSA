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
    int N;
    cin >> N;
    ull pow = 1;
    for (int i = 1; i <= N; ++i) {
        pow = ((pow % E) * (i % E)) % E;
    }
    cout << pow << endl;
}