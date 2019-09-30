#include <iostream>

using namespace std;

int main(void)
{
    uint64_t a, b, x;
    cin >> a >> b >> x;

    uint64_t fb = b / x + 1;
    uint64_t fa = (a == 0 ? 0 : (a - 1) / x + 1);
    cout << fb - fa << endl;

    return 0;
}