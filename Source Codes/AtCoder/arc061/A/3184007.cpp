#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string str; cin >> str;

    unsigned long ans = 0;
    int len = str.size() - 1;
    int bit = 0;
    for (; bit < (1 << len); ++bit) {
        int digit = 0;
        for (int j = len; j >= 0; --j) {
            int value = str[j] - '0';
            ans += value * long(pow(10, digit));
            if (bit & (1 << (len - j))) digit = 0;
            else                    ++digit;
        }
    }

    cout << ans << endl;

    return 0;
}