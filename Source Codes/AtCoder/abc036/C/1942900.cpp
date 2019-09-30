/**
 * C - ??
 */

#include <iostream>
#include <map>

using namespace std;

int main() {

    int N;
    int a[100'000];
    map<int, int> A;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        A[a[i]] = 0;
    }

    int j = 0;

    for (auto &a_ : A) {
        a_.second = j++;
    }

    for (int i = 0; i < N; i++) {
        cout << A[a[i]] << endl;
    }
}