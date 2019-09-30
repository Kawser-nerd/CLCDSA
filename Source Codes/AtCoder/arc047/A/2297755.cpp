#include <iostream>

using namespace std;

int main() {

    int n, l;
    cin >> n >> l;

    string s;
    cin >> s;

    int cur_tabs = 1, crashed = 0;
    for (int i = 0; i < s.size(); i++) {
        cur_tabs += ((s[i] == '+')? 1 : -1);
        if (cur_tabs > l) {
            crashed++;
            cur_tabs = 1;
        }
    }
    cout << crashed << endl;

    return 0;
}