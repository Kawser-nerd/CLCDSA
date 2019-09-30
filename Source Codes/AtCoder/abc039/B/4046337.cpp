#include <iostream>

using namespace std;

int main(void)
{
    uint64_t X;
    cin >> X;

    for(uint64_t n = 1; n <= 1000; ++n)
    {
        if(X == n * n * n * n)
        {
            cout << n << endl;
            return 0;
        }
    }
    return 0;
}