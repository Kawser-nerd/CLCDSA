#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << (x - z) / (y + z) << endl;
    return 0;
}