#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int x = 0;
    int xmax = 0;
    for(int i = 0; i < N; ++i)
    {
        char si;
        cin >> si;
        x += (si == 'I' ? 1 : -1);
        xmax = max(xmax, x);
    }
    cout << xmax << endl;
    return 0;
}