#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    vector<int> A;
    for (int i = 0; i < M; ++i) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    int cost0 = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] >= X) break;
        cost0 += 1;
    }
    int costn = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] <= X) continue;
        ++costn;
    }
    cout << min(cost0, costn) << endl;
}