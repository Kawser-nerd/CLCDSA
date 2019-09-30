
#include <stdio.h>

int main() {
    int cases;
    scanf("%d\n", &cases);
    for (int n = 1; n <= cases; ++n) {
        int count;
        scanf("%d\n", &count);
        int friend[1000];
        for (int i = 0; i < count; ++i) {
            scanf("%d", &friend[i]);
            friend[i]--;
        }
        int length[1000];
        int last[1000];
        for (int i = 0; i < count; ++i) {
            int visited[1000] = {0};
            int current = i;
            visited[current] = 1;
            length[i] = 1;
            while (!visited[friend[current]]) {
                current = friend[current];
                visited[current] = 1;
                ++length[i];
            }
            last[i] = current;
        }
        int max = 0;
        for (int i = 0; i < count; ++i)
            if (length[i] == 2 && friend[i] > i) {
                int first = 0;
                int second = 0;
                for (int j = 0; j < count; ++j) {
                    if (last[j] == i && length[j] > first)
                        first = length[j];
                    if (last[j] == friend[i] && length[j] > second)
                        second = length[j];
                }
                max += first + second - 2;
            }
        for (int i = 0; i < count; ++i) {
            int cycle = length[friend[last[i]]];
            if (cycle > max)
                max = cycle;
        }
        printf("Case #%d: %d\n", n, max);
    }
    return 0;
}

