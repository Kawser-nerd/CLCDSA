#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    string ans = "";
    for(const auto& e : s)
    {
        if(e == 'B')
        {
            if(ans.size())
                ans.resize(ans.size() - 1);
        }
        else
        {
            ans += e;
        }
    }

    cout << ans << endl;
    return 0;
}