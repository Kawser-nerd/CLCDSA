# include <iostream>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    if (a == b and b != c) cout << c << endl;
    if (b == c and c != a) cout << a << endl;
    if (c == a and a != b) cout << b << endl;
    return 0;
}