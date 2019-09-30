#include <iostream>
#include <string>

int main() {
using namespace std;
string c;
cin >> c;
if(c.size() == 1 && c[0] == 'a') {
cout << "-1" << endl;
} else {
cout << "a" << endl;
}
}