#include <cstdio>

using namespace std;
#define MAX_N 86
typedef long long unsigned int ll;
ll L[MAX_N];

ll f(int d) {
    if (L[d] != 0) return L[d]; 
    if (d == 0 ) return 2;
    else if (d == 1) return 1;
    else {
        return L[d] = f(d - 1) + f(d - 2);
    }
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        L[i] = 0;
    }
    int n;
    scanf("%d", &n);
    printf("%lld\n", f(n));
    return 0;
}