#include <iostream>
#include <climits>
using namespace std;

int main() {
    int i, n, m, x, y, a[110000], b[110000], ct=0, *port_a=a, *port_b=b, r=0;
    cin >> n >> m >> x >> y;
    for(i=0; i<n; i++) cin >> a[i];
    for(i=0; i<m; i++) cin >> b[i];
    a[n] = INT_MAX; b[m] = INT_MAX;
    while(1) {
        port_a = lower_bound(port_a, a+n, ct);
        if(*port_a == a[n]) break;
        port_b = lower_bound(port_b, b+m, (*port_a)+x);
        if(*port_b == b[m]) break;
        ct = *port_b + y;
        r++;
    }
    cout << r << endl;
}