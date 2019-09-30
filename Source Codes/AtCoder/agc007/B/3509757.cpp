#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;


int main()
{
    int N, p;

    cin >> N;

    int a[20005];
    int b[20005];

    for (int i = 0; i < N;i++)
    {
        int p;
        cin >> p;
        a[p - 1] = 20000 * p + 1 + i;
        b[p - 1] = 4 * pow(10, 8) - 20000 * p + 1;
    }

    for (int i = 0; i < N;i++)
    {
        cout << a[i];
        if(i == N-1)
        {
            cout << endl;
        }
        else
        {
            cout << ' ';
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << b[i];
        if (i == N-1)
        {
            cout << endl;
        }
        else
        {
            cout << ' ';
        }
    }

    return 0;
}