#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s; cin >> s;
    cout << (count(s.begin(), s.end(), 'a') && count(s.begin(), s.end(), 'b') && count(s.begin(), s.end(), 'c') ? "Yes" : "No") << endl;

    return 0;
}