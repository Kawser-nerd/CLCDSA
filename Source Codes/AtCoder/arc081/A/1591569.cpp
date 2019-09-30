#include <iostream>
using namespace std;

int main() {
    int n, a[100000], x, y, k;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<>());
    for(k = 0, x = a[k++]; k < n && x != a[k]; x = a[k++]) ;
    for(k++,   y = a[k++]; k < n && y != a[k]; y = a[k++]) ;
    if (k == n) y = 0;
    cout << (long long)x * y << endl;
    return 0;
}