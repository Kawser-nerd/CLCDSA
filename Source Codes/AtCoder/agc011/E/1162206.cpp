#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 500111

int const dim = 500055;

int n, i, sum, k;
char s[maxN];
int data[maxN];

void mult() {
    int i;

    for (i = 1; i <= n; i++)
        data[i] *= 9;

    for (i = 1; i <= dim; i++) {
        data[i + 1] += data[i] / 10;
        data[i] %= 10;
        sum += data[i];
    }
}

void add() {
    sum += 9;
    data[1] += 9;

    for (int pos = 1; data[pos] >= 10; pos++) {
        sum += data[pos] / 10;
        data[pos + 1] += data[pos] / 10;
        sum -= data[pos];
        data[pos] %= 10;
        sum += data[pos];
    }
}

int main()
{
 //   freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++)
        data[n - i + 1] = s[i] - '0';

    mult();
    for (k = 1; true; k++) {
        add();
        if (sum <= 9 * k) {
            printf("%d", k);
            return 0;
        }
    }


    return 0;
}