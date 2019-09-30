#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1;
    cin >> s1;
    s1.replace(5,1," ");
    s1.replace(13,1," ");
    cout << s1;
}