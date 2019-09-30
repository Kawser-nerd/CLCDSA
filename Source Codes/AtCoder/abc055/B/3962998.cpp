#include <iostream>

using namespace std;

int main(void)
{
    uint64_t N;
    cin >> N;

    uint64_t p = 1;
    uint64_t d = 1000000000 + 7;
    for(uint64_t n = 1; n <= N; ++n)
    {
        p *= n;
        p %= d;
    }
    cout << p << endl;
    return 0;
}