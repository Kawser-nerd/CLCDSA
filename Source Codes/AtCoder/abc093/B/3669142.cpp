#include <iostream>

using namespace std;

int main(void)
{
    int A, B, K;
    cin >> A >> B >> K;

    int a = A + K - 1;
    a = a > B ? B : a;
    int b = B - K + 1;
    b = b < A ? A : b;

    if(a >= b) b = a + 1;

    for(int i = A; i <= a; ++i)
        cout << i << endl;

    for(int i = b; i <= B; ++i)
        cout << i << endl;

    return 0;
}