#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int m;
    cin >> m;

    if (m < 100) {
        cout << "00" << endl;
    } else if (m <= 5000) {
        cout << setw(2) << setfill('0') << m / 100 << endl;
    } else if (m <= 30000) {
        cout << m / 1000 + 50 << endl;
    } else if (m <= 70000) {
        cout << (m / 1000 - 30) / 5 + 80 << endl;
    } else {
        cout << 89 << endl;
    }

    return 0;
}