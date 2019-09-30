#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <string>
#include <list>

using namespace std;
using ll = long long;

int main(int argc, char const* argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i=0; i<N; ++i) {
        int pi;
        cin >> pi;
        p[pi-1] = i;
    }
    int count = 0;
    int max = 0;
    for (int i=0; i<N-1; ++i) {
        if (p[i] < p[i+1]) {
            ++count;
        }
        else {
            if (count > max) max = count;
            count = 0;
        }
    }
    if (count > max) max = count;
    max = N - max - 1;
    cout << max << '\n';
    return 0;
}