#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES      1000000
#define HASH_MODULO     5470427

#define INF             1000000000

#define MAXW            20
#define MAX_QUERIES     50
#define MAX_QUERY_VALUE 250

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int statesU[MAX_STATES];
int statesV[MAX_STATES];
int statesSum[MAX_STATES];
int statesDist[MAX_STATES];
int statesNext[MAX_STATES];

int bfsQueue[MAX_STATES];
int qLow, qHi;

int statesHead[HASH_MODULO];
int totalStates;

char field[MAXW][MAXW];
int query[MAX_QUERIES];
bool queryFound[MAX_QUERY_VALUE + 1];

bool can[MAXW][MAXW];
bool can2[MAXW][MAXW];

int hashCode(int u, int v, int sum) {
    int hash = (((u << 5) + v) << 20) + sum;
    hash = hash % HASH_MODULO;
    if (hash < 0) {
        hash += HASH_MODULO;
    }
    return hash;
}

int getStateNumber(int u, int v, int sum, bool addNew) {
    int hash = hashCode(u, v, sum);

    for (int cur = statesHead[hash]; cur != -1; cur = statesNext[cur]) {
        if (statesU[cur] == u && statesV[cur] == v && statesSum[cur] == sum) {
            return cur;
        }
    }

    if (!addNew) {
        return -1;
    }

    statesU[totalStates] = u;
    statesV[totalStates] = v;
    statesSum[totalStates] = sum;
    statesDist[totalStates] = INF;

    statesNext[totalStates] = statesHead[hash];
    statesHead[hash] = totalStates;

    if (totalStates == MAX_STATES - 1) {
        fprintf(stderr, "Out of memory\n");
        exit(239);
    }

    return totalStates++;
}

void initHash() {
    totalStates = 0;
    for (int i = 0; i < HASH_MODULO; i++) {
        statesHead[i] = -1;
    }
}

void solveSingleTest(int testNumber) {
    int w, q;

    initHash();
    
    scanf("%d %d", &w, &q);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            char ch = getc(stdin);
            while (ch == '\n' || ch == '\r') {
                ch = getc(stdin);
            }
            field[i][j] = ch;
        }
    }

    for (int i = 0; i <= MAX_QUERY_VALUE; i++) {
        queryFound[i] = true;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &query[i]);
        queryFound[query[i]] = false;
    }
    int queryFoundCount = 0;
    for (int i = 1; i <= MAX_QUERY_VALUE; i++) {
        if (queryFound[i]) {
            queryFoundCount++;
        }
    }

    qLow = qHi = 0;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            if (('0' <= field[i][j]) && (field[i][j] <= '9')) {
                int state = getStateNumber(i, j, field[i][j] - '0', true);
                statesDist[state] = 0;
                bfsQueue[qHi++] = state;
            }
        }
    }

    int maxDist = INF;
    while (qLow < qHi) {
        int curState = bfsQueue[qLow++];
        int u = statesU[curState];
        int v = statesV[curState];
        int sum = statesSum[curState];
        int dist = statesDist[curState];

        if (dist >= maxDist) {
            continue;
        }
        
        for (int dir1 = 0; dir1 < 4; dir1++) {
            int u1 = u + dx[dir1];
            int v1 = v + dy[dir1];
            if (u1 < 0 || u1 >= w || v1 < 0 || v1 >= w) {
                continue;
            }
            char sign = field[u1][v1];
            for (int dir2 = 0; dir2 < 4; dir2++) {
                int u2 = u1 + dx[dir2];
                int v2 = v1 + dy[dir2];
                if (u2 < 0 || u2 >= w || v2 < 0 || v2 >= w) {
                    continue;
                }
                int digit = field[u2][v2] - '0';
                int newSum;
                if (sign == '+') {
                    newSum = digit + sum;
                } else {
                    newSum = digit + sum - 2 * (field[u][v] - '0');
                }
                int newState = getStateNumber(u2, v2, newSum, true);
                if (dist + 1 < statesDist[newState]) {
                    statesDist[newState] = dist + 1;
                    bfsQueue[qHi++] = newState;
                }

                if ((1 <= newSum) && (newSum <= MAX_QUERY_VALUE) && !queryFound[newSum]) {
                    queryFound[newSum] = true;
                    queryFoundCount++;

                    if (queryFoundCount == MAX_QUERY_VALUE) {
                        maxDist = dist + 1;
                    }
                }
            }
        }
    }

    printf("Case #%d:\n", testNumber);
    for (int i = 0; i < q; i++) {
        int minDist = INF;
        int firstDigit = 10;
        for (int u = 0; u < w; u++) {
            for (int v = 0; v < w; v++) {
                int neededState = getStateNumber(u, v, query[i], false);
                if (neededState == -1) {
                    continue;
                }
                int curDist = statesDist[neededState];
                if ((curDist < minDist) || ((curDist == minDist) && (field[u][v] - '0' < firstDigit))) {
                    minDist = curDist;
                    firstDigit = field[u][v] - '0';
                }
            }
        }

        for (int u = 0; u < w; u++) {
            for (int v = 0; v < w; v++) {
                int neededState = getStateNumber(u, v, query[i], false);
                if (neededState == -1) {
                    can[u][v] = false;
                    continue;
                }
                int curDist = statesDist[neededState];
                can[u][v] = ((curDist == minDist) && (field[u][v] - '0' == firstDigit));
            }
        }

        if (minDist == 0) {
            printf("%d\n", firstDigit);
            continue;
        }

        printf("%d", firstDigit);
        int goalSum = query[i];
        for (int step = 0; step < minDist; step++) {
            char nextDigit = 'x';
            char nextSign = 'x';

            for (int u = 0; u < w; u++) {
                for (int v = 0; v < w; v++) {
                    if (!can[u][v]) {
                        continue;
                    }

                    for (int dir1 = 0; dir1 < 4; dir1++) {
                        int u1 = u + dx[dir1];
                        int v1 = v + dy[dir1];
                        if (u1 < 0 || u1 >= w || v1 < 0 || v1 >= w) {
                            continue;
                        }
                        char sign = field[u1][v1];
                        for (int dir2 = 0; dir2 < 4; dir2++) {
                            int u2 = u1 + dx[dir2];
                            int v2 = v1 + dy[dir2];
                            if (u2 < 0 || u2 >= w || v2 < 0 || v2 >= w) {
                                continue;
                            }

                            int neededSum;
                            if (sign == '+') {
                                neededSum = goalSum - (field[u][v] - '0');
                            } else {
                                neededSum = goalSum - (field[u][v] - '0') + 2 * (field[u2][v2] - '0');
                            }
                            int state = getStateNumber(u2, v2, neededSum, false);
                            if (state == -1 || statesDist[state] != minDist - step - 1) {
                                continue;
                            }

                            if ((sign < nextSign) || ((sign == nextSign) && (field[u2][v2] < nextDigit))) {
                                nextDigit = field[u2][v2];
                                nextSign = sign;
                            }
                        }
                    }
                }
            }

            for (int u = 0; u < w; u++) {
                for (int v = 0; v < w; v++) {
                    can2[u][v] = false;
                }
            }
            int newGoal;
            for (int u = 0; u < w; u++) {
                for (int v = 0; v < w; v++) {
                    if (!can[u][v]) {
                        continue;
                    }

                    for (int dir1 = 0; dir1 < 4; dir1++) {
                        int u1 = u + dx[dir1];
                        int v1 = v + dy[dir1];
                        if (u1 < 0 || u1 >= w || v1 < 0 || v1 >= w) {
                            continue;
                        }
                        char sign = field[u1][v1];
                        for (int dir2 = 0; dir2 < 4; dir2++) {
                            int u2 = u1 + dx[dir2];
                            int v2 = v1 + dy[dir2];
                            if (u2 < 0 || u2 >= w || v2 < 0 || v2 >= w) {
                                continue;
                            }

                            int neededSum;
                            if (sign == '+') {
                                neededSum = goalSum - (field[u][v] - '0');
                            } else {
                                neededSum = goalSum - (field[u][v] - '0') + 2 * (field[u2][v2] - '0');
                            }
                            int state = getStateNumber(u2, v2, neededSum, false);
                            if (state == -1 || statesDist[state] != minDist - step - 1) {
                                continue;
                            }

                            if ((sign == nextSign) && (field[u2][v2] == nextDigit)) {
                                newGoal = neededSum;
                                can2[u2][v2] = true;
                            }
                        }
                    }
                }
            }
            for (int u = 0; u < w; u++) {
                for (int v = 0; v < w; v++) {
                    can[u][v] = can2[u][v];
                }
            }
            goalSum = newGoal;
            printf("%c%c", nextSign, nextDigit);
        }
        printf("\n");
    }
}

int main() {
    int t;

    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solveSingleTest(i + 1);
    }
    return 0;
}
