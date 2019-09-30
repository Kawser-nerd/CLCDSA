#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <chrono>
#include <vector>

using namespace std;

int main()
{
    int N, i, n;
    cin >> N;
    n = N;
    vector<int> b(N), ans;
    for (i = 0; i < N; i++)
    {
        cin >> b[i];
    }
    while (b.size())
    {
        int z = -1;
        for (i = 0; i < b.size(); i++)
        {
            if (b[i] == i + 1)
            {
                z = i + 1;
            }
        }
        if (z == -1)
        {
            cout << z << endl;
            return 0;
        }
        ans.push_back(z);
        b.erase(b.begin() + z - 1);
    }
    reverse(ans.begin(), ans.end());
    for (i = 0; i < N; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}