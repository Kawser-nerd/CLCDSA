#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

set<pair<int, int> > ans;

int main()
{
    int N;
    cin >> N;
    int cs = (N % 2 == 0 ? N + 1 : N);
    for (int i = 1;i <= N;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            if(i + j != cs && i != j)
            {
                if(i > j)
                {
                    ans.insert(make_pair(j, i));
                }
                else
                {
                    ans.insert(make_pair(i, j));
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }
    return 0;
}