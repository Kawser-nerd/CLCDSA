#include <iostream>
#include <string>

using namespace std;
bool is_checked[30];

int main() {
    string s;
    cin >> s;
    for (char c: s) {
        int numc = c - 'a';
        if (is_checked[numc]) {
            cout << "no" << endl;
            return 0;
        }
        is_checked[numc] = true;
    }
    cout << "yes" << endl;
}