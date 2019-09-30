#include <cstdio>
#include <set>

using namespace std;

int main() {
    char x[3];
    set<char> se;
    scanf("%c%c%c", &x[0], &x[1], &x[2]);
    for (int i = 0; i < 3; i++) {
        se.insert(x[i]);
    }
    if (se.size() == 3) {
        printf("Yes\n");
    }else {
        printf("No\n");
    }
    return 0;
}