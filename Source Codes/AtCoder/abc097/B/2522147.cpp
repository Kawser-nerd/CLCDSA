#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int x;
    scanf("%d", &x);

    int result = 1;
    for (int b = 2; b <= 31; b++) {
        for (int p = 2; pow(b, p) <= x; p++) {
            if (pow(b, p) > result) { result = pow(b, p); }
        }
    }
    printf("%d\n", result);
}