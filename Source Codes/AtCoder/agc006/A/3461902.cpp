#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int N;
    string s, t;

    cin >> N;
    cin >> s >> t;
    int i, j;
    int h = 0;

    for (i = 0; i < N;i++)
    {
        for (j = 0; j < N - i; j++)
        {
            if(s[i + j] != t[j])
            {
                break;
            }
            h = max(h, j + 1);
        }
    }

    cout <<  2 * N - h << endl;

    return 0;
}