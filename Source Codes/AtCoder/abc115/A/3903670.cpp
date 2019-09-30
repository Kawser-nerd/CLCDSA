#include <iostream>

using namespace std;

int main() {
    int d; cin >> d;
    cout << (d == 25 ? "Christmas" : (d == 24 ? "Christmas Eve" : (d == 23 ? "Christmas Eve Eve" : "Christmas Eve Eve Eve"))) << endl;
    return 0;
}