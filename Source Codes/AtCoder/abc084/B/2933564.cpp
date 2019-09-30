#include <iostream>
#include <regex>

using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    string s; cin >> s;
    regex regex(R"(\d+)");

    // for (int i = 0; i < s.length(); i++) {
    //     cout << *(s.begin() + i) << endl;
    // }


    if (regex_match(s.begin(), s.begin() + a, regex) && *(s.begin() + a) == '-' && regex_match(s.begin() + (a + 1), s.end(), regex)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}