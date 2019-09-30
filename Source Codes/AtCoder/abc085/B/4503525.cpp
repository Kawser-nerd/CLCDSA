#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;  cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int d;  cin >> d;
        v.push_back(d);
    }

    sort(v.begin(), v.end(), greater<int>());

    int ret = 1;
    for (int i = 1; i < n; i++) if (v[i] < v[i - 1]) ret++;

    cout << ret << endl;

    return 0;
}