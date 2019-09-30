#include<iostream>
#include<vector>
using namespace std;

// ????????????
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> a[i];
    }
    // ?????????
    int dst = a[0];
    for(int i = 1 ; i < n ; ++i) {
        // cout << "gcd\tdst:" << dst << "\ta[" << i << "]:" << a[i] << endl;
        dst = gcd(dst, a[i]);
    }
    cout << dst << endl;
    return 0;
}