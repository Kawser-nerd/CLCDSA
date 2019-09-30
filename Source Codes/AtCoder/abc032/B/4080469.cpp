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
    int k;
    cin >> s >> k;

    set<string> st;
    if(s.size() >= k)
    {
        for(int i = 0; i <= s.size() - k; ++i)
        {
            st.insert(s.substr(i, k));
        }
    }
    cout << st.size() << endl;
    return 0;
}