#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    for(int i = 8; i >= 0; --i)
    {
        if(N & (1 << i))
        {
            cout << (N & (1 << i)) << endl;
            break;
        }
    }
    return 0;
}