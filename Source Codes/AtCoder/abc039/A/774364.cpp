#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    cout << ((A*B*2) + (B*C*2) + (C*A*2)) << endl;
    
    return 0;
}