#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans, arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = n - i - 1; j >= 0; j--) {
            if (arr[j] == j + 1) {
                ans.push_back(*(arr.begin() + j));
                arr.erase(arr.begin() + j);
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto a : ans) {
        cout << a << '\n';
    }

    return 0;
}