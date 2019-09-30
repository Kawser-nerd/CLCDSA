#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    vector<int> A;
    cin  >> N;
    for (size_t i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    int max_diff = 0;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = i+1; j < N; j++) {
            max_diff = max(max_diff, abs(A[i] - A[j]));
        }
    }

    cout << max_diff << endl;

    return 0;
}