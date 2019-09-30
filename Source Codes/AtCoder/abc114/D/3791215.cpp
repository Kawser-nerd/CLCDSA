#include <iostream>
using namespace std;

int p[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int m[25];
int ans = 0;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 25; i++) {
        int tmp = n;
        while (tmp > 0) {
            tmp /= p[i];
            m[i] += tmp;
        }
    }

    if (m[0] >= 74) {
        ans++;
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            if (i == j) { continue; }
            if (m[i] >= 2 && m[j] >= 24) { ans++; }
            if (m[i] >= 4 && m[j] >= 14) { ans++; }
            for (int k = 0; k < 25; k++) {
                if (i == k || j == k) { continue; }
                if (m[i] >= 2 && m[j] >= 4 && m[k] >= 4 && j < k) { ans++; }
            }
        }
    }

    cout << ans << endl;
}