#include <iostream>

using namespace std;

const int EMPTY = 0;

int main() {

    int N, M;

    cin >> N >> M;

    //
    int disks[N + 1];

    for (int i = 0; i <= N; i++) {
        disks[i] = i;
    }

    int prev = 0, next;

    for (int i = 0; i < M; i++) {
        cin >> next;
        disks[prev] = disks[next];
        disks[next] = EMPTY;
        prev = next;
    }

    //
    int cases[N + 1];

    for (int i = 0; i <= N; i++) {
        cases[disks[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        cout << cases[i] << endl;
    }
}