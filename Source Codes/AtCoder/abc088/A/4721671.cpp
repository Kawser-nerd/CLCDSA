#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A;
    cin >> N >> A;

    if ((N % 500) <= A)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}