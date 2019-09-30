#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    
    int a[m+1];
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    int i = 0;
    a[m] = x;
    while (a[i] < x) { i++; }
    printf("%d\n", min(i, m-i));
    return 0;
}