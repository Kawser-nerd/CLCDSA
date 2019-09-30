#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    int maxOut = -1001;
    maxOut = max(maxOut, A+B);
    maxOut = max(maxOut, A-B);
    maxOut = max(maxOut, A*B);

    cout << maxOut << endl;
}