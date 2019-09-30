#include <iostream>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    cout << (string::npos != string("aeiou").find(s) ? "vowel" : "consonant") << endl;
    return 0;
}