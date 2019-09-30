#include <iostream>
#include <string>
using namespace std;

bool checkEvenSentence(string str)
{
    int l = str.size();
    if (l % 2 != 0) return false;

    if (str.substr(0, l/2) == str.substr(l/2, l/2)) return true;
    return false;
}

int main()
{
    string str;
    cin >> str;
    str.pop_back();
    
    for (;;) {
        if (checkEvenSentence(str)) {
            cout << str.size() << endl;
            break;
        } else if (str.size() == 0) {
            exit(1);
        } else {
            str.pop_back();
        }
    }
    return 0;
}