#include <iostream>

using namespace std;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;
    if(A == B) cout << C << endl;
    else if(B == C) cout << A << endl;
    else cout << B << endl;
    return 0;
}