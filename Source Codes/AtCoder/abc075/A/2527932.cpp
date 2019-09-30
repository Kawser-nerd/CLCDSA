#include <cstdio>
#include <map>

using namespace std;

int main() {
    map<int, int> m;
    for (int i = 0; i < 3; i++) {
        int d;
        scanf("%d", &d);
        m[d]++;
    }
    for (auto x : m) {
        if(x.second == 1) printf("%d\n", x.first);
    }
    return 0;
}