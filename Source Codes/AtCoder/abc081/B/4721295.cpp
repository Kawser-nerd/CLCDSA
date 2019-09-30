#include <iostream>

using namespace std;

long long N[200];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> N[i];
        if (N[i] % 2 != 0)
        {
            cout << "0" << endl;
            return 0;
        }
    }

    int result = 0;
    while (true)
    {
        for (int i = 0; i < n; ++i)
        {
            if (N[i] == 0)
            {
                continue;
            }

            if (N[i] % 2 == 0)
            {
                N[i] /= 2;
            }
            else
            {
                cout << result << endl;
                return 0;
            }
        }
        ++result;
    }

    return 0;
}