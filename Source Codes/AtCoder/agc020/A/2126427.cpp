#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A, B;
    cin >> N >> A >> B;

    int DISTANCE = B - A;
    if (DISTANCE % 2 == 0)
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Borys" << endl;
    }

    return 0;
}