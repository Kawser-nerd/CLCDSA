#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a.rbegin(), a.rend());

    int former = 0, latter = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            former += a[i];
        } else {
            latter += a[i];
        }
    }
    printf("%d\n", former);

    return 0;
}