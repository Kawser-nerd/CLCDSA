#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> vc;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        vc.push_back(a);
    }

    int oddCnt = 0;
    for (int e: vc) if (e % 2 != 0) ++oddCnt;

    cout << (oddCnt % 2 == 0 ? "YES" : "NO") << endl;

    return 0;
}