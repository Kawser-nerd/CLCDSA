#include <iostream>

using namespace std;

int main()
{
    int n = 100001;
    bool prime[n];
    int c[n+1];

    for (int i = 2; i < n; i++) {
        prime[i] = true;
    }

    for (int i = 2; i < n; i++) {
        if (prime[i] == false) continue;
        for (int j = i + 1; j < n; j++) {
            if (j % i == 0) {
                prime[j] = false;
            }
        }
    }

    for (int i = 3; i < n; i += 2) {
        if (prime[i] && prime[(i+1)/2]) {
            c[i]++;
        }
    }
    for (int i = 3; i < n; i++) {
        c[i] += c[i-1];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", c[r] - c[l-1]);
    }

    return 0;
}