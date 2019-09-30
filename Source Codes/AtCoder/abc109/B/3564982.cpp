#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
    int N;
    string s0, s1;
    map<string, int> m;

    cin >> N;
    cin >> s0;
    m.insert(make_pair(s0, 0));

    bool is_ok = true;
    for(int i = 1; i < N; ++i)
    {
        cin >> s1;

        if(s0.back() != s1.front())
        {
            is_ok = false;
        }

        pair<map<string, int>::iterator, bool> ret = m.insert(make_pair(s1, 0));
        if(!ret.second)
        {
            is_ok = false;
        }

        s0 = s1;
    }

    if(is_ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}