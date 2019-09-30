#include <iostream>

using namespace std;

int main(void)
{
    int A, B;
    cin >> A >> B;
    int c = A + B;
    if(c < 10) cout << c << endl;
    else cout << "error" << endl;
    return 0;
}