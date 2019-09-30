#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    string str; cin >> str;
    int aIndex = INT_MAX;
    int zIndex = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'A')       aIndex = min(i, aIndex);
        else if (str[i] == 'Z')  zIndex = max(i, zIndex);
    }

    cout << zIndex - aIndex + 1 << endl;
    return 0;
}