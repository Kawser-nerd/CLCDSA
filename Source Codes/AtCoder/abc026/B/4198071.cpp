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
    vector<double> R;
    for (int i = 0; i < N; ++i) {
        double Ri;
        cin >> Ri;
        R.push_back(Ri);
    }
    sort(R.rbegin(), R.rend());
    double area = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            area += R[i] * R[i] * pi;
        } else {
            area -= R[i] * R[i] * pi;
        }
    }
    printf("%.10lf\n", area);
}