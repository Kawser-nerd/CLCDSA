#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int x, a, b;
    scanf("%d %d %d", &x, &a, &b);
    if (abs(float(x - a)) < abs(float(x - b))) printf("A\n");
    else printf("B\n");
    return 0;
}