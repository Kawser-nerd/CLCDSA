#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string x = to_string(s.size() - 2);
    cout << s[0] + x + s[s.size()-1] << endl;
}