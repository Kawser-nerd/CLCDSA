#include <iostream>
#include <algorithm>

using namespace std;

string solve (int n);
int digit_sum (int n);

int main () {

    int n;
    cin >> n;

    cout << solve(n) << endl;

    return 0;
}

string solve (int n) {

    if (n == 1) {
        return "Not Prime";
    }

    bool isPrime = true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        return "Prime";

    } else {
        int r = n % 10;
        if (r % 2 != 0 && r != 5 && digit_sum(n) % 3 != 0) {
            return "Prime";

        } else {
            return "Not Prime";
        }
    }
}

int digit_sum (int n) {

    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}