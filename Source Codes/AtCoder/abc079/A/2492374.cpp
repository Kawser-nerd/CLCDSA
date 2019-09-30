#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    int tmp, tmp_before = 0;
    while(n > 0) {
        tmp = n % 10;
        if (tmp == tmp_before) ans++;
        else ans = 0;
        if (ans + 1>= 3) {
            printf("Yes\n");
            return 0;
        }
        tmp_before = tmp;
        n /= 10;
    }
    printf("No\n");
    return 0;
}