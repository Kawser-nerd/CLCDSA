#include <iostream>

using namespace std;

int main()
{
    int w, a, b;
    cin >> w >> a >> b;
    int ret = 0;

    if ((b <= a && a <= b + w) || (a <= b && b <= a + w)) {
        cout << "0" << endl;
    } else {
        if (a + w < b) {
            cout << b - a - w << endl;
        } else if (b + w < a) {
            cout << a - b - w << endl;
        }
    }
    return 0;
}