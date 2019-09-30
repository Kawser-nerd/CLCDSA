#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b - c - d > 0) printf("Left\n");
    else if (a + b - c - d == 0) printf("Balanced\n");
    else printf("Right\n");
    return 0;
}