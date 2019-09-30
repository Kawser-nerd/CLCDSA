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
    string s;
    cin >> s;

    string ans = "";
    char c = s[0];
    int n = 0;
    for(auto& e : s)
    {
        if(c == e)
            n++;
        else
        {
            ans += c;
            ans += to_string(n);
            c = e;
            n = 1;
        }
    }
    ans += c;
    ans += to_string(n);

    cout << ans << endl;
    return 0;
}