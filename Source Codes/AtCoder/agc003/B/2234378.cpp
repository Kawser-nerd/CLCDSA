#include <iostream>

#define MAXN 100000
using namespace std;
typedef long long int ll;
int a[MAXN];
int n;
ll sol = 0;
bool pass = false;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (pass) {
            if (a[i] & 1) {
                pass = false;
                a[i]--;
                sol++;
            } else if (a[i] > 1) {
                a[i] -= 2;
                sol++;
            } else if (a[i] == 1) {
                a[i]--;
                sol++;
                pass = false;
            } else {
                pass = false;
            }
        } else {
            if (a[i] & 1) {
                pass = true;
                a[i]--;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        sol += a[i] / 2;
    }

    cout << sol << "\n";

    return 0;
}