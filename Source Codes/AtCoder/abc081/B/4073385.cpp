#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int as[n];
    for (int i = 0; i < n; i++)
        cin >> as[i];

    int count = 0;
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            if (as[i] % 2 != 0)
                goto RESULT;
            as[i] /= 2;
        }
        count++;
    }

RESULT:
    cout << count << endl;

    return 0;
}