#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a(10, 0);
    for(int i = 0; i < 3; i++) {
        int inp; cin >> inp; a[inp]++;
    }
    if(a[5]==2 && a[7]==1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}