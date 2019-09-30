#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char c;
        scanf("%c", &c);
        if (c == 'Y') {
            printf("Four\n");
            return 0;
        }
    }
    printf("Three\n");
    return 0;
}