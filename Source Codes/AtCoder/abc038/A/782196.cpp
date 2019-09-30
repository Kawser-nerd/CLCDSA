#include <iostream>
#include <string>
using namespace std;
int main(void){
string s;
cin >> s;
cout << (s[s.size()-1]=='T'?"YES":"NO") << endl;
}