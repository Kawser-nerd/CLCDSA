#include <iostream>

using namespace std;

int main() {

    char C, c;
    cin >> C >> c;

    cout << ((C == c - 32)? "Yes" : "No") << endl;

    return 0;
}