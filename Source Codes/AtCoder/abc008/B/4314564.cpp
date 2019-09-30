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
    cin >> N;
    map<string, int> M;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        ++M[S];
    }
    string ans;
    int cnt = -1;
    for (auto&& it : M) {
        if (it.second > cnt) {
            cnt = it.second;
            ans = it.first;
        }
    }
    cout  << ans << endl;
}