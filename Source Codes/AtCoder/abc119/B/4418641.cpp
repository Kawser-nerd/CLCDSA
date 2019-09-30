#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n;
    double sum = 0.0;
    cin >> n;

    double x;
    string unit;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cin >> unit;
        if (unit == "JPY") {
            sum += x;
        } else {
            sum += x * 380000.0;
        }
    }
    cout << sum << endl;
    return 0;
}