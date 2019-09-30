#include <iostream>

using namespace std;

int main() {
    int c500 = 0, c100 = 0, c50 = 0, x = -1, sum_money;
    cin >> c500 >> c100 >> c50 >> x;
    int s[500 * 50 + 100 * 50 + 50 * 50 + 10] = {};
    for (int i = 0; i < c500 + 1; i++) {
        for (int j = 0; j < c100 + 1; j++) {
            for (int k = 0; k < c50 + 1; k++) {
                sum_money = 500 * i + 100 * j + 50 * k;
                s[sum_money]++;
            }
        }
    }
    cout << s[x] << endl;
    return 0;
}