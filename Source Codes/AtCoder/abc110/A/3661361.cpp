#include <cstdio>
#include <vector>
#include <functional>

using namespace std;

int main() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        int d;
        scanf("%d", &d);
        a.push_back(d);
    }
    sort(a.begin(), a.end(), greater<int>());
    printf("%d\n", a[0] * 10 + a[1] + a[2]);
    return 0;
}