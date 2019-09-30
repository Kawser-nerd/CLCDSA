#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void)
{
    string S;
    cin >> S;
    set<char> s;
    for(auto& e : S)
    {
        auto p = s.insert(e);
        if(!p.second)
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}