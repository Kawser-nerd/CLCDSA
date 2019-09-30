#include <iostream>
#include <string>

using namespace std;

string solve (int n) {

    if (n == 1) {
        return "BOWWOW";

    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return "BOWWOW";
            }
        }
    }

    return "WANWAN";
}

int main () {

    int n;
    cin >> n;

    int sum = (n * (1 + n)) / 2;

    cout << solve(sum) << endl;

    return 0;
}