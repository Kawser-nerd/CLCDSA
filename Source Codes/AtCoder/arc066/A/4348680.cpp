#include <iostream>
#include <limits.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

ll b2(int k) {
    ll rt = 1;
    for (int i = 0; i < k; i++) {
        rt *= 2;
        rt %= 1000000007;
    }
    return rt;
}

int main(void){
    int n, a[100010], b[100010];
    cin >> n;
    for (int i = 0; i < n; i++) b[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    
    for (int i = n - 1; i >= 0; i -= 2) {
        if (i != 0 && b[i] != 2) {
            cout << 0 << endl;
            return 0;
        }
        if (i == 0 && b[i] != 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << b2(n/2) << endl;
    
    
}