#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long long N;

int main()
{
    cin >> N;
    long long A;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        if(A % 2 == 1)
        {
            cnt++;
        }
    }

    if(cnt % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}