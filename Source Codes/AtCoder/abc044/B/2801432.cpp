#include <iostream>
#include <string>

using namespace std;

int main() {
    string str; cin >> str;
    int ascii[26] = {};
    for (char s: str) ++ascii[s - 97];
    bool isBeautiful = true;
    for (auto e: ascii) {
        isBeautiful = e % 2 == 0 ? true : false;
        if (!isBeautiful) break;
    }

    cout << (isBeautiful ? "Yes" : "No") << endl;
    return 0;
}