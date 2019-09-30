#include <iostream>

using namespace std;

typedef long long int ll;

int main() {

    ll curpos = 0;
    ll X;

    cin >> X;

    int ans = 0;
    ll delta = 1;
    while (curpos < X) {
        curpos += delta;
        ++delta;
        ++ans;
    }

    cout << ans;

    return 0;
}