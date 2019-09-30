#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<long long> a(n+1);
    vector<long long> b(n+1);
    vector<long long> r(n+1);

    for(int i = 1; i <= n; i++) {
        r[p[i]] = i;
    }

    for(int i = 1; i <= n; i++) {
        a[i] = 30000 * i;
    }

    for(int i = 1; i <= n; i++) {
        b[i] = 30000 * (n - i) + r[i];
    }

    for(int i = 1; i <= n; i++) {
        if(i != 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;

    for(int i = 1; i <= n; i++) {
        if(i != 1) {
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;

    return 0;
}