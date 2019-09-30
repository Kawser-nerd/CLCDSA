#include <iostream>

using namespace std;

int main(void)
{
    int A, B;

    cin >> A >> B;

    if(!((A & 0x1) && (B & 0x1)))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}