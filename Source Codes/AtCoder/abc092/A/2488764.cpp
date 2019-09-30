#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", min(a, b) + min(c, d));
    return 0;
}