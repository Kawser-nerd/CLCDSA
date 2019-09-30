#include <iostream>
#include <cstdlib>
using namespace std;

auto main() -> int {
    char a, b;
    cin >> a >> b;
    if(tolower(a)==tolower(b)) cout << "Yes" << endl;
    else cout << "No" << endl;
}