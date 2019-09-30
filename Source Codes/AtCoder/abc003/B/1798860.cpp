#include <iostream>

using namespace std;

int main()
{
    string s, t;
    string atcoder = "atcoder@";
    cin >> s >> t;

    size_t n = s.size();
    bool result = true;
    for (auto i = 0u; i < n; ++i) {
        if (s[i] == '@') {
            if (atcoder.find(t[i]) == string::npos) {
                result = false;
                break;
            }
        } else if (t[i] == '@') {
            if (atcoder.find(s[i]) == string::npos) {
                result = false;
                break;
            }
        } else if (s[i] != t[i]) {
            result = false;
            break;
        }
    }
    cout << (result ? "You can win" : "You will lose") << endl;

    return 0;
}