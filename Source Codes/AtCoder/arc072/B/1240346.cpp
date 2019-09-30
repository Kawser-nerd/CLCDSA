#include <iostream>

using namespace std;
int main() {
    long long x, y;
    cin >> x >> y;
    cout << (abs(x-y)<=1?"Brown":"Alice") << endl;

    return 0;
}