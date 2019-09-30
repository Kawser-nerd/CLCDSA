#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    cout << s.front() << s.length() - 2 << s.back() << '\n';
}