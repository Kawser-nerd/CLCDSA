#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <sysexits.h>

using namespace std;

int N;
string answer;
vector<int> b, ans;

int main()
{
    cin >> N;
    string b;
    for (int i = 0; i < N;i++)
    {
        int bi;
        cin >> bi;
        bi--;
        b.push_back(bi);
    }
    bool f;
    for (int i = 0; i < N; i++)
    {
        f = false;
        for (int j = N - 1 - i; 0 <= j; j--)
        {
            if(b[j] == j)
            {
                ans.push_back(j);
                b.erase(b.begin() + j);
                f = true;
                break;
            }
        }
        if(f == false)
        {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    if (f == true)
    {
        for (int i : ans)
        {
            cout << i + 1 << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}