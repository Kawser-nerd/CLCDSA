#include<iostream>
#include<bitset>

using namespace std;

int n;
int a[2000];
int sum = 0;

const int SUM_MAX = 2000 * 2000 + 1;
bitset<SUM_MAX> dp;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    dp = bitset<SUM_MAX>("1");

    for (int i = 0; i < n; ++i) {
        dp = dp | (dp << a[i]);
    }

    int i = (sum + 1) / 2;
    while(!dp[i]) i++;

    cout << i << endl;

}