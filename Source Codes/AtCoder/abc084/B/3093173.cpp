#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b; cin >> a >> b;
    string str; cin >> str;

    bool flag = true;
    int len = a + b;

    for (int i = 0; i < len; ++i) {
        if (i == a) {
            flag = str[a] == '-';
        } else {
            flag = 48 <= str[i] && str[i] <= 57;
        }
        if (!flag) break;
    }

    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}