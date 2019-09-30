#include <iostream>

#define MAX_N 100000

using namespace std;

int main(void)
{
    unsigned long long n, a[MAX_N + 1], i, count, answer;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = a[n - 1];
    count = 1;
    answer = 0;
    for (i = 0; i < n; i++) {
        if (a[i] >= a[i + 1]) {
            answer += count * (count + 1) / 2;
            count = 1;
            continue;
        }
        count++;
    }
    cout << answer << endl;
    return 0;
}