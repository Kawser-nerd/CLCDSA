#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for(int i = 0; i < n; ++i) {
        a[i] = b[n - 1 - i] = (i+1) * 20000;
    }

    int p;
    for(int i = 0; i < n; ++i) {
        cin >> p;
        b[p - 1] += i;
    }

    for(int i = 0; i < n; ++i) {
        cout << a[i];
        if (i == n - 1) cout << endl;
        else cout << " ";
    }

    for(int i = 0; i < n; ++i) {
        cout << b[i];
        if (i == n - 1) cout << endl;
        else cout << " ";
    }
}