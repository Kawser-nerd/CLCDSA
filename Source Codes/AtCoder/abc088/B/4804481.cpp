#include <iostream>
#include<math.h>
#include <vector>

using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // ??
    //sort(a.begin(), a.end());

    // ??
    sort(a.begin(), a.end(), [](const int x, const int y) { return x > y; });
    // sort(a.begin(), a.end(), greater<int>());  // a[0:N] ?????????

    int alice = 0;
    int bob = 0;
    for (int j = 0; j < N; ++j) {
        if (j % 2 == 0) {
            alice += a[j];
        } else {
            bob += a[j];
        }
    }

    cout << alice - bob << endl;
}