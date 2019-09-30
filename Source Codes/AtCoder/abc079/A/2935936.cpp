#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s; cin >> s;
    bool good = false;
    for (int i = 0; i < 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            good = true;
            break;
        }
    }

    cout << (good ? "Yes" : "No") << endl;


    return 0;
}