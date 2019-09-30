#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int offset = 0;
    int balance = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] == '(') {
            balance++;
        } else {
            balance--;
        }
        offset = min(offset, balance);
    }

    if (balance < 0) {
        int rebalance = 0;
        offset = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (s[i] == '(') {
                rebalance--;
            } else {
                rebalance++;
            }
            offset = min(offset, rebalance);
        }
    }
    
    string res = "";
    if (balance < 0) {
        if (offset < 0) {
            for (int i = 0; i < (-1 * balance) - (offset); ++i) {
                res += '(';
            }

            res += s;

            for (int i = 0; i < (-1 * offset); ++i) {
                res += ')';
            }
        } else {
            for (int i = 0; i < -1 * balance; ++i) {
                res += '(';
            }

            res += s;
        }
    } else if (balance > 0) {
        if (offset < 0) {
            for (int i = 0; i < (-1 * offset); ++i) {
                res += '(';
            }

            res += s;

            for (int i = 0; i < balance - (offset); ++i) {
                res += ')';
            }
        } else {
            res += s;
            for (int i = 0; i < balance; ++i) {
                res += ')';
            }
        }
    } else { // balance == 0
        if (offset < 0) {
            for (int i = 0; i < -1 * offset; ++i) {
                res += '(';
            }

            res += s;
            
            for (int i = 0; i < -1 * offset; ++i) {
                res += ')';
            }
        } else {
            res = s;
        }
    }
    
    // cout << "balance: " << balance << ", offset: " << offset << endl;
    cout << res << endl;
}