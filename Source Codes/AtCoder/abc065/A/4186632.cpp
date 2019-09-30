# include <iostream>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    long long x, a, b;
    cin >> x >> a >> b;

    long long current = b - a;
    long long limit = a;

    if (current <= 0) {
        cout << "delicious" << endl;
    }
    else if (current <= x) {
        cout << "safe" << endl;
    }
    else {
        cout << "dangerous" << endl;
    }

    return 0;
}