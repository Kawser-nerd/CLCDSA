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


int main() {
    int N;
    cin >> N;
    vector<tuple<int, string>> v;
    for (int i = 0; i < N; ++i) {
        string S;
        int P;
        cin >> S >> P;
        v.push_back(make_tuple(P, S));
    }
    sort(v.rbegin(), v.rend());
    int sum = 0;
    for (int i = 1; i < N; ++i) {
        sum += get<0>(v[i]);
    }
    if (get<0>(v[0]) > sum) {
        cout << get<1>(v[0]) << endl;
    } else {
        cout << "atcoder" << endl;
    }
}