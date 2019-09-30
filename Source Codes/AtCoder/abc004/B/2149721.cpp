#include <iostream>

using namespace std;

int main()
{
    char c[16];

    for (int i = 0; i < 16; i++) {
        cin >> c[i];
    }
    for (int i = 15; i >= 0; i--) {
        cout << c[i];
        cout << ((i % 4 == 0)? '\n': ' ');
    }

    return 0;
}