#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _queue {
    int x, y;
    struct _queue *next;
} queue;

queue *que;
queue *last;

queue* new(int x, int y) {
    queue *_que;
    _que = (queue*)malloc(sizeof(queue));
    _que->x = x;
    _que->y = y;
    _que->next = NULL;
    return _que;
}

void push(int x, int y) {
    queue *new_queue = new(x, y);
    if (que == NULL) {
        que = new_queue;
        last = new_queue;
    } else {
        last->next = new_queue;
        last = new_queue;
    }
}

void pop(int *rx, int *ry) {
    *rx = que->x;
    *ry = que->y;
    queue *old = que;
    que = que->next;
    free(old);
    if (que == NULL) last = NULL;
}

int main() {
    char mp[64][64];
    int ret[64][64];
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int r, c, sy, sx, gy, gx;
    scanf("%d%d%d%d%d%d", &r, &c, &sy, &sx, &gy, &gx);
    for (int i = 0; i < r; i++) scanf("%s", mp + i);
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) ret[i][j] = -1;
    ret[sy-1][sx-1] = 0;
    que = new(sx, sy);
    last = que;
    while (que != NULL) {
        int x, y;
        pop(&x, &y);
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx > 0 && nx <= c && ny > 0 && ny <= r && mp[ny-1][nx-1] == '.' && ret[ny-1][nx-1] == -1) {
                ret[ny-1][nx-1] = ret[y-1][x-1] + 1;
                push(nx, ny);
            }
        }
    }
    printf("%d\n", ret[gy-1][gx-1]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:48:39: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[64]’ [-Wformat=]
     for (int i = 0; i < r; i++) scanf("%s", mp + i);
                                       ^
./Main.c:47:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d", &r, &c, &sy, &sx, &gy, &gx);
     ^
./Main.c:48:33: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (int i = 0; i < r; i++) scanf("%s", mp + i);
                                 ^