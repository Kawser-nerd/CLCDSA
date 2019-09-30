#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <string>

using namespace std;


int main() {
    int t;
    scanf("%d", &t);

    for (int z = 1; z <= t; z++) {
        int n, j;
        scanf("%d %d", &n, &j);
        printf("Case #%d:\n", z);

        for (int i = 0; i < j; i++) {
            string cur;
            int tmp = i;

            for (int k = 0; k < n/2 - 2; k++) {
                if (tmp & 1)
                    cur += "11";
                else
                    cur += "00";
                tmp >>= 1;
            }

            printf("11%s11 3 4 5 6 7 8 9 10 11\n", cur.c_str());
        }
    }
}
