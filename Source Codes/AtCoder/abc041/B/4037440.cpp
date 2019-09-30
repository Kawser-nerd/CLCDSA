#include <iostream>

using namespace std;

int main(void)
{
    uint64_t A, B, C;
    cin >> A >> B >> C;

    uint64_t d = 1000000000 + 7;
    cout << (((A * B) % d) * C) % d << endl;
    return 0;
}