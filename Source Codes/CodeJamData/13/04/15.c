#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_TYPE 200
#define MAX_N 20
#define bool int
#define true 1
#define false 0

int total_keys[MAX_KEY_TYPE + 1], keys[MAX_KEY_TYPE + 1];
int num, k, n;
int res[MAX_N], need[MAX_N], visit[MAX_N], have_num[MAX_N];
int have[MAX_N][MAX_KEY_TYPE];
bool found;

bool cut(int depth) {
    int current_key = need[res[depth]];
    bool ok = true;

    //    printf("%d\n", i);

    if (keys[current_key] == 0) {
        for (int q = 0; q < n; ++q)
            if (!visit[q] && need[q] == current_key) {
                ok = false;
                break;
            }
        for (int q = 0; q < n; ++q)
            if (!visit[q] && need[q] != current_key && !ok)
                for (int l = 0; l < have_num[q]; l++)
                    if (have[q][l] == current_key) {
                        ok = true;
                        break;
                    }
    }

    return !ok;
}

int dfs(int depth) {
//    for (int i = 0; i != n - 1; i++)
//        printf(" %d", res[i] + 1);
//    printf(" %d\n", res[n - 1] + 1);
    if (depth == n) {
        found = true;
        printf("Case #%d:", num + 1);
        for (int i = 0; i != n - 1; i++)
            printf(" %d", res[i] + 1);
        printf(" %d\n", res[n - 1] + 1);
    }
    else {
        int dire = 0;
        for (int i = 0; i != n; i++)
            if (keys[need[i]] > 0 && visit[i] == 0 && !found) {
                // if (depth > 0) {
                //   bool appeared = false;
                //   for (int j = 0; j != have_num[res[depth - 1]]; j++)
                //     if (need[i] == have[res[depth-1]][j]) {
                //       appeared = true;
                //       break;
                //     }
                //   if (!appeared && ++dire > 1)
                //     continue;
                // }
                keys[need[i]]--;
                visit[i] = 1;
                res[depth] = i;
                for (int j = 0; j != have_num[i]; j++)
                    keys[have[i][j]]++;

                if (!cut(depth))
                    dfs(depth + 1);

                keys[need[i]]++;
                visit[i] = 0;
                res[depth] = -1;
                for (int j = 0; j != have_num[i]; j++)
                    keys[have[i][j]]--;
            }
    }
}

int main() {

    FILE *fin = fopen("qr-d.in", "r");
    int T;
    fscanf(fin, "%d\n", &T);

    for (num = 0; num < T; num++) {
        fscanf(fin, "%d %d\n", &k, &n);
        for (int i = 0; i < MAX_KEY_TYPE; i++) {
            keys[i + 1] = 0;
            total_keys[i+1] = 0;
        }
        for (int i = 0; i < k; i++) {
            int key_type;
            fscanf(fin, "%d", &key_type);
            keys[key_type]++;
            total_keys[key_type]++;
        }
        for (int i = 0; i < n; i++) {
            res[i] = -1;
            visit[i] = 0;
            fscanf(fin, "%d %d", &need[i], &have_num[i]);
            for (int j = 0; j < have_num[i]; j++) {
                fscanf(fin, "%d", &have[i][j]);
                total_keys[have[i][j]]++;
            }
            fscanf(fin, "\n");
        }

        // printf("%d %d\n", n, k);
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            total_keys[need[i]]--;
            if (total_keys[need[i]] < 0) {
                flag = false;
                break;
            }
        }

        found = false;
        if (flag)
            dfs(0);
        if (!found)
            printf("Case #%d: IMPOSSIBLE\n", num + 1);
    }

    return 0;
}
