#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;


int main() {
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> m;

    for (int x : a) {
        m[x]++;
    }

    if (m.size() > 2) {
        cout << "No" << endl;
        return 0;
    }

    if (m.size() == 1) {
        if (m.begin()->first <= n / 2 || m.begin()->first == n - 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        return 0;
    }

    auto p = *m.begin();
    auto q = *next(m.begin());

    if (p.first + 1 == q.first && p.second <= p.first && n - p.first > (p.first - p.second) + 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}