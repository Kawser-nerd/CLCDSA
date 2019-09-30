#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a(3);
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    cout << a[0]*10 + a[1] + a[2] << endl;
}