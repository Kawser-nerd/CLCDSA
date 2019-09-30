#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

string A;

int K[200005];
vector<int> cpos[26];

int main()
{
    cin >> A;
    int used[26];
    int cnt = 0;
    int k = 1;
    memset(used, 0, sizeof(used));
    for (int i = A.length() - 1; i >= 0; i--)
    {
        char c = A[i];
        int n = c - 'a';
        cpos[n].insert(cpos[n].begin(), i);
        if(used[n] == 0)
        {
            used[n] = 1;
            cnt++;
        }
        if(cnt == 26)
        {
            memset(used, 0, sizeof(used));
            cnt = 0;
            k++;
        }
        K[i] = k;
    }
    string ans = "";
    int anslen = 0;
    int cp = 0;
    //cout << "K[0] = " << K[0] << endl;
    for (int i = 0; anslen != K[0];)
    {
        //cout << "i = " << i << endl;
        for (int j = 0; j < 26; j++)
        {
            
            int flag = 0;
            vector<int>::iterator r = cpos[j].begin();
            int p = -1;
            if (cpos[j].size() != 0)
            {
                r = lower_bound(cpos[j].begin(), cpos[j].end(), i);
                p = *r;
                if (K[p + 1] == K[i] - 1 || r == cpos[j].end())
                {
                    flag = 1;
                }
            }
            else
            {
                flag = 1;
            }
            if (flag == 1)
            {
                ans += j + 'a';
                anslen++;
                i = p + 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}