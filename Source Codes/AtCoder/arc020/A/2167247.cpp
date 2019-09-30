#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a = abs(a);
    b = abs(b);
    if (a == b) {
        cout << "Draw" << endl;
    } else if (a < b) {
        cout << "Ant" << endl;
    } else {
        cout << "Bug" << endl;
    }
}