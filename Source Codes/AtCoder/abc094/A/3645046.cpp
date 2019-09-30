#include <iostream>

using namespace std;

int main(void)
{
    int A, B, X;
    cin >> A >> B >> X;
    bool ans;
    if(X - A < 0)
        cout << "NO" << endl;
    else if((X - A) > B)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}