#include <iostream>
#include <cmath>

using namespace std;

int n;
int min_ = INT_MAX;

int main() {

    cin >> n;

    for (int i = 1; i <= sqrt(n); i++) {
        min_ = min(min_, abs((n / i) - i) + n % i);
    }

    cout << min_ << endl;
}