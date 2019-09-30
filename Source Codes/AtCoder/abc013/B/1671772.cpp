//
// B - ?
//

#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << min(abs(a - b), 10 - abs(a - b)) << endl;
}