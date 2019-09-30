#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    string w;
    cin >> w;

    vector<int> v(26, 0);
    for(const auto& e : w)
        v[e - 'a']++;

    bool ans = true;
    for(const auto& e : v)
    {
        if(e % 2)
            ans = false;
    }
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}