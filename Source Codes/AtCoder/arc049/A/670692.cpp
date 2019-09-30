#include <iostream>
#include <string>
using namespace std;
 
int main() {
string s;
int a[4];
cin >> s;
for(int i = 0; i < 4; i++) cin >> a[i];
int j = 0;
for(int i = 0; i < s.size(); i++) {
if(j < 4 && a[j] == i) {cout << "\""; j++;}
cout << s[i];
}
if(j < 4) cout << "\"";
cout << endl;
}