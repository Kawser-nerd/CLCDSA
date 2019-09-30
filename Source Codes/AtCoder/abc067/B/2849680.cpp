#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;   cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int l;  cin >> l;
        v.push_back(l);
    }

    sort(v.begin(), v.end(), greater<int>());

    int ret = 0;
    for (int i = 0; i < k; i++) ret += v[i];

    cout << ret << endl;

    return 0;
}