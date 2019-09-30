#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>

using namespace std;

int n;
int a[100000];
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while(true) {
        bool same = true;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] != a[i + 1]) {
                same = false;
                break;
            }
        }
        if (same) break;
        int mina = *min_element(a, a + n);
        for (int i = 0; i < n; ++i) {
            a[i] = (a[i] - 1) % mina + 1;
        }
    }
    cout << a[0] << endl;
}