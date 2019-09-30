#include <cstdio>

using namespace std;

int main()
{
    int x;
    scanf("%d", &x);

    int p = 0;
    for (int i = 1;; ++i) {
        p += i;
        if (p >= x) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}