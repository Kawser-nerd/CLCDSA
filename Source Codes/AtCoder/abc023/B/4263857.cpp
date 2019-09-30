#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;
const double pi = 3.14159265359;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    if (N % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    int i = 0;
    int mid = N / 2;
    for (; mid + i < N; ++i) {
        if (S[mid - i] == 'b' && S[mid + i] == 'b') continue;
        if (S[mid - i] == 'a' && S[mid + i] == 'c') continue;
        if (S[mid - i] == 'c' && S[mid + i] == 'a') continue;
        cout << -1 << endl;
        return 0;
    }
    cout << i - 1 << endl;
}