#include <iostream>

using namespace std;
int main(void) {
    int t,x;
    cin >> t;
    cin >> x;
    auto ans = t / static_cast<double>(x);
    cout << ans;
    return 0;
}