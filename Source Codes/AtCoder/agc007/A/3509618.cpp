#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

string s[10];

int main()
{
    int H, W;

    cin >> H >> W;

    for (int i = 0; i < H;i++)
    {
        cin >> s[i];
    }

    int cnt = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W;j++)
        {
            if(s[i][j] == '#')
            {
                cnt++;
            }
        }
    }

    if(cnt == H + W - 1)
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }

        return 0;
}