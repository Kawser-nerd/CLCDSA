#include <iostream>

using namespace std;

int main() {

    string s;
    cin >> s;

    int grade = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= '0' && s[i] <= '9') && grade == 0) {
            grade = (int)s[i] - '0';
            continue;
        }
        if ((s[i] >= '0' && s[i] <= '9') && grade != 0) {
            grade *= 10;
            grade += (int)s[i] - '0';
            continue;
        }
    }

    cout << grade << endl;

    return 0;
}