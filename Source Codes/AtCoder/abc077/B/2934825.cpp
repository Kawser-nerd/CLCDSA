#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n; cin >> n;
    for (int i = n; i >= 1; i--) {
        if (sqrt(i) == int(sqrt(i))) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}