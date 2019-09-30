#include <iostream>

using namespace std;

int main() {

    string s;
    cin >> s;

    bool north = false, south = false, east = false, west = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N') north = true;
        if (s[i] == 'S') south = true;
        if (s[i] == 'E') east = true;
        if (s[i] == 'W') west = true;
    }
    cout << ((north == south && east == west)? "Yes" : "No") << endl;

    return 0;
}