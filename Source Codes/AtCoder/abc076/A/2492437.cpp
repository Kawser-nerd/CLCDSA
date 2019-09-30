#include <cstdio>

using namespace std;

int main() {
    int r, g;
    scanf("%d %d", &r, &g);
    printf("%d\n", g + (g - r));
    return 0;
}