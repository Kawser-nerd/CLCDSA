#include <iostream>

using namespace std;

int main(void)
{
    int K;
    cin >> K;

    int even = K / 2;
    int odd = even + (K & 0x1);
    cout << even * odd << endl;
    return 0;
}