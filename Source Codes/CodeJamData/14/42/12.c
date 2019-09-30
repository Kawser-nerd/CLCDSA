#include <stdio.h>
#define INF 0x3f3f3f3f

int v[20];
int seq[20];
int order[20];
int original[20];
int mark[20];
int best;
int n;

int count_inversion(void) {
    int i, j;
    int sim;
    int count = 0;
    int temp;

    sim = 1;

    for (i = 0; i < n - 1; i++) {
        if (seq[i] > seq[i + 1]) {
            break;
        }
    }

    for (; i < n - 1; i++) {
        if (seq[i] < seq[i + 1]) {
            sim = 0;
            break;
        }
    }

    if (sim == 0) {
        return INF;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (original[i] == seq[j]) {
                order[i] = j;
                break;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (order[j - 1] > order[j]) {
                count++;
                temp = order[j];
                order[j] = order[j - 1];
                order[j - 1] = temp;
            }
        }
    }

    return count;
}

void backtrack(int v[], int pos) {
    int aux;
    int i;

    if (pos == n) {
        aux = count_inversion();
        if (aux < best) {
            best = aux;
        }
    }

    for (i = 0; i < n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            seq[pos] = v[i];
            backtrack(v, pos + 1);
            mark[i] = 0;
        }
    }

    return;
}

int main(void) {
    int t;
    int caso;

    int i;

    scanf(" %d", &t);

    for (caso = 1; caso <= t; caso++) {
        scanf(" %d", &n);

        for (i = 0; i < n; i++) {
            scanf(" %d", &v[i]);
            original[i] = v[i];
        }

        for (i = 0; i < n; i++) {
            mark[i] = 0;
        }

        best = INF;
        backtrack(v, 0);

        printf("Case #%d: %d\n", caso, best);
    }
    return 0;
}
