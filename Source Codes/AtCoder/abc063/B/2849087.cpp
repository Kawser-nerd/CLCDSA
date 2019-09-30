#include <iostream>
#include <string>

using namespace std;

int main() {
    string str; cin >> str;
    int arr[26] = {0};
    for (auto s: str) {
        arr[s - 'a']++;
    }

    string ret = "yes";
    for (auto e: arr) {
        if (e > 1) {
            ret = "no";
            break;
        }
    }

    cout << ret << endl;

    return 0;
}