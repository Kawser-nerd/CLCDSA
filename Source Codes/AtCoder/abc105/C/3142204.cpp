#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 0;
    long long x = 1;
    string s = (n != 0 ? "" : "0");

    while (n != 0) {
        if (n % (x * -2) != 0) {
            s = "1" + s;
            n -= x;
        } else {
            s = "0" + s;
        }
        x *= -2;
    }

    cout << s << endl;
}