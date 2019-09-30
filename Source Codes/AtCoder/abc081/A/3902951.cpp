#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    cout << count(s.begin(), s.end(), '1') << "\n";
    return 0;
}