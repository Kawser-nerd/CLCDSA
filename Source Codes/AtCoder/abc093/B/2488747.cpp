#include <cstdio>
#include <set>

using namespace std;

int main() {
    int a, b, k;
    set<int> se;
    scanf("%d %d %d", &a, &b, &k);
    for (int i = a; i < a + k; i++) {
        if (i > b ) break;
        se.insert(i);
    }
    for (int i = b; i > b - k; i--) {
        if (i < a) break;
        se.insert(i);
    }
    set<int>::iterator pos = se.begin();
    while(pos != se.end()) {
        printf("%d\n", *pos);
        pos++;
    }
    return 0;
}