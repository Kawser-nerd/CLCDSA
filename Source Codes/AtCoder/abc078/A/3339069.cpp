#include <iostream>
using namespace std;
int main() {
    string x, y;
    cin >> x >> y;
    int a, b;
    a = stoi(x, nullptr, 16);
    b = stoi(y, nullptr, 16);
    if(a>b) cout << ">" << endl;
    else if(a<b) cout << "<" << endl;
    else cout << "=" << endl;
    return 0;
}