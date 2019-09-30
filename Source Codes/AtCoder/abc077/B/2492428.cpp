#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int sqrt_n = int(sqrt(double(n)));
    printf("%d\n", int(pow(double(sqrt_n), 2.0)));
    return 0;
}