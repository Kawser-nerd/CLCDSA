#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int counter = 0;
    if (s[0] == '1') ++counter;
    if (s[1] == '1') ++counter;
    if (s[2] == '1') ++counter;
    cout << counter << endl;
}