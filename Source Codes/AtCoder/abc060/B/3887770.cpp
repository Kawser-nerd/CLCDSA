#include <iostream>

using namespace std;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;

    bool ans = false;
    for(int i = 1; i < 101; ++i)
    {
        if((A * i) % B == C)
        {
            ans = true;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}