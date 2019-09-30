#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int a[300005];

int main()
{
    int N, x;

    cin >> N >> x;

    if(x == 1 || x == 2*N - 1)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < 2 * N - 1;i++)
    {
        a[i] = i + 1;
    }

    swap(a[x - 1], a[N - 1]);
    swap(a[0], a[N - 2]);
    swap(a[2 * N - 2], a[N]);

    for (int i = 0; i < 2 * N - 1; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}