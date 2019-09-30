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
ull e = 10007;
const double pi = 3.14159265359;


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    int ans = A[0];
    for (int i = 1; i < N; ++i) {
        ans = gcd(ans, A[i]);
    }
    cout << ans << endl;
}