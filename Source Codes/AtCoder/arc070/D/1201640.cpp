#include <cstdio>
#include <vector>
#include <stack>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
using namespace std;

int main() {
    int a, b; scanf("%d%d", &a, &b);
    if (a <= b) {
        printf("Impossible\n");
    } else {
        auto query = [](int i, int j) {
            printf("? %d %d\n", i, j);
            fflush(stdout);
            char c; scanf(" %c", &c);
            switch (c) {
                case 'Y': return true;
                case 'N': return false;
                default: assert (false);
            }
        };
        stack<int> chain;
        repeat (i, a + b) {
            if (chain.empty()) {
                chain.push(i);
            } else {
                if (query(chain.top(), i)) {
                    chain.push(i);
                } else {
                    chain.pop();
                }
            }
        }
        assert (not chain.empty());
        int honest = chain.top();
        vector<bool> result(a + b);
        repeat (i, a + b) {
            result[i] = query(honest, i);
        }
        printf("! ");
        repeat (i, a + b) printf("%d", int(result[i]));
        printf("\n");
    }
    return 0;
}