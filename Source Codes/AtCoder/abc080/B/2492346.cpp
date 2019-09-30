#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    int tmp = n;
    while (tmp > 0) {
        sum += tmp % 10;
        tmp /= 10;
    }
    if (n % sum) printf("No\n");
    else printf("Yes\n");
    return 0;
}