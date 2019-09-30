#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int N;
    stack<char> stk;
    string s;
    string l = "", r = "";

    cin >> N;
    cin >> s;
    string ans = s;

    int size = s.size();
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == '(' && s[i + 1] == ')') {
            s.erase(s.begin() + i, s.begin() + i + 2);
            i -= 2;
            size -= 2;
            continue;
        }
    }
    for (char c : s) {
        if (c == '(')
            r += ")";
        else if (c == ')')
            l += "(";
    }
    cout << l + ans + r << endl;
    return 0;
}