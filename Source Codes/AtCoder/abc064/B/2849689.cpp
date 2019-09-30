#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;  cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;  cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int ret = 0;
    for (int i = 1; i < n; i++) ret += v[i] - v[i - 1];

    cout << ret << endl;
 
    return 0;
}