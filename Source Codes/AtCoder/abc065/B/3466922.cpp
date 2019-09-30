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
 
    int cnt = 0;
    int index = 1;
    bool ok = false;
    while (cnt < n) {
        index = vc[index - 1];
        ok = index == 2;
        ++cnt;
        if (ok == true) break;
    } 
 
    cout << (ok ? cnt : -1) << endl;
 
    return 0;
}