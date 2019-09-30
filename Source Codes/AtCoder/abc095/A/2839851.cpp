#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;   cin >> str;
    int topping = 0;
    for (auto s: str)   if (s == 'o')   topping++;
    cout << 700 + topping * 100 << endl;
    return 0;
}