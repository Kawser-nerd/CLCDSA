#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    cout << (s <= "2019/04/30" ? "Heisei" : "TBD") << endl;
}