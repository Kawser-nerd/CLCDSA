#include <iostream>

using namespace std;

int main() {

    char X;
    string s;

    cin >> X;
    cin >> s;

    string ans;

    for (auto c:s) if (c != X) ans += c;

    cout << ans << endl;
}