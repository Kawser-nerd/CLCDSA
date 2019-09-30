#include <iostream>


using namespace std;


int sum(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int a, b;
    cin >> a >> b;

    int diff = b - a;
    int x = -1;
    for (int i = 1; i < 999; ++i) {
        int d = sum(i + 1) - sum(i);
        if (d == diff) {
            x = sum(i) - a;
            break;
        }
    }
    cout << x << endl;
}