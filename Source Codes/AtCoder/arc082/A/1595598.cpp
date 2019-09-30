#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    const int LIM = (int)(1e5 + 5);
    vector<int> cnt(LIM, 0);
    for (auto a : A) {
        for (int j = -1; j <= 1; j++) {
            int b = a + j;
            if (b < 0 || b >= LIM) continue;
            cnt[b] += 1;
        }
    }
    cout << *max_element(cnt.begin(), cnt.end()) << endl;
}