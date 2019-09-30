#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    if(S == "b")
        ans = 0;
    else
    {
        ans = -1;
        string s = "b";
        int n = 0;
        while(s.size() < S.size())
        {
            s = "a" + s + "c";
            if(S == s)
            {
                ans = 3 * n + 1;
                break;
            }
            s = "c" + s + "a";
            if(S == s)
            {
                ans = 3 * n + 2;
                break;
            }
            n++;
            s = "b" + s + "b";
            if(S == s)
            {
                ans = 3 * n;
                break;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}