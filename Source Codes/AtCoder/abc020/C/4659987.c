#include <stdio.h>
#include <stdlib.h>
long H, W, T;
int sx, sy, gx, gy;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
// ?????
typedef struct point {
    long x, y;
} point_t;
// ???
typedef struct heap {
    point_t P;  // ??
    int exist; // ???????? 1
    int distance;
} heap_t;
// ????
long lPow(long n, long m);    // ????
void setBoard (char **s, long **dist);    // ?????
void swapQue (heap_t *a, heap_t *b);   // ??????
void InitDist (int H, int W, long **dist);   // ??????
void InitQue(int H, int W, heap_t que[]);   // ???????
void addQue (int x, int y, int n, long **dist, heap_t node[]);   // ?????
void deleteQue (int x, heap_t node[]); // ??????
void pushHeap (int x, int y, long **dist, heap_t node[]);  // ???????????????
heap_t popHeap (heap_t node[]); // ?????????????????
long Dijkstra (long cost, long **dist, char **s);  // ????????
void BinarySearch (long **dist, char **s);    // ????
//???
int main(int argc, char const *argv[]) {
    // ??
    char **s;
    long **dist;    // ?????????
    // ??
    scanf("%ld %ld %ld\n", &H, &W, &T);
    // ?????
    s = (char **)malloc(sizeof(char *)*H);
    dist = (long **)malloc(sizeof(long *)*H);
    for (size_t i = 0; i < H; i++) {
        s[i] = (char *)malloc(sizeof(char)*(W+1));
        dist[i] = (long *)malloc(sizeof(long)*W);
    }
    // ????????????????????
    setBoard(s, dist);
    // ?????????????
    BinarySearch(dist, s);
    // ?????
    for (size_t i = 0; i < H; i++) {
        free(s[i]); free(dist[i]);
    }
    free(s); free(dist);
    return 0;
}

// ????
long lPow(long n, long m) {
    if (m == 0) {
        return 1;
    } else if (m == 1) {
        return n;
    } else if (m%2 == 2) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// ????
void setBoard (char **s, long **dist) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j <= W; j++) {
            scanf("%c", &s[i][j]);
            if (s[i][j] == 'S') {
                sx = j, sy = i; // ??????????
                s[i][j] = '.';
            }
            if (s[i][j] == 'G') {
                gx = j, gy = i; // ?????????
                s[i][j] = '.';
            }
        }
    }
    //printf("sy %d sx %d gy %d gx %d\n", sy, sx, gy, gx);
}
// ??????
void swapQue (heap_t *a, heap_t *b) {
    heap_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
// ??????
void InitDist(int H, int W, long **dist) {
    // ????????????
    long INF = lPow(10, 10)+lPow(10, 6);
    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < W; j++) {
            dist[i][j] = INF;
        }
    }
    //  ???????0
    dist[sy][sx] = 0;
}
// ???????
void InitQue(int H, int W, heap_t que[]) {
    for (size_t i = 0; i < H*W; i++) {
        que[i].exist = 0;
    }
}
//  ?? x,y???? n?????????
void  addQue (int x, int y, int n, long **dist, heap_t node[]) {
    node[n].P.x = x;
    node[n].P.y = y;
    node[n].distance = dist[y][x];
    node[n].exist = 1;  // ??
}
// x??????????
void deleteQue (int n, heap_t node[]) {
    node[n].exist = 0;
}
// ???????????????
void pushHeap (int x, int y, long **dist, heap_t node[]) {
    int n  = 0; // ????
    while (node[n].exist != 0) {    // ????????
        n++;
    }
    addQue(x, y, n, dist, node);
    // ??????????????
    while (n != 0) {
        int parent = (n-1)/2; // ????
        // ???????????????????
        if (node[parent].distance > node[n].distance) {
            swapQue(&node[n], &node[parent]);
        }
        n = parent;
    }
}
// ?????????????????
heap_t popHeap (heap_t node[]) {
    int n  = 0; // ????
    while (node[n].exist != 0) {    // ????????
        n++;
    }
    int last = n-1;   // ????????
    heap_t pop = node[0];    // ???????
    node[0] = node[last];   // ????????
    //swapQue(&node[0], &node[last]);
    for (int i = 0, child; (child=2*i+1) < n; i++) {
        // ???????????????????
        if ((child != last) && (node[child].distance > node[child+1].distance)) {
            child++;
        }
        // ????????
        if (node[i].distance > node[child].distance) {
            swapQue(&node[i], &node[child]);
        }
        i = child;
    }
    deleteQue(last, node);
    return pop;
}

// ???????
long Dijkstra (long c, long **dist, char **s) {
    //printf("call Dijkstra\n");
    heap_t *que;
    que = (heap_t *)malloc(sizeof(heap_t)*H*W);
    InitDist(H, W, dist);
    InitQue(H, W, que);
    addQue(sx, sy, 0, dist, que);
    // ??
    while (que[0].exist != 0) {
        heap_t buf = popHeap(que);  // ?????
        int X = buf.P.x, Y = buf.P.y;
        //printf("que[0] y:%d x:%d\n", Y, X);
        for (size_t i = 0; i < 4; i++) {
            int nx = X+dx[i], ny = Y+dy[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) { continue; }
            //printf("ny:%d nx:%d\n", ny, nx);
            long cost = (s[ny][nx]=='.' ? 1L : c);    // ?????1?????c
            //printf("cost %ld\n", cost);
            if (dist[ny][nx] > dist[Y][X] + cost) {
            dist[ny][nx] = dist[Y][X] + cost;
            //printf("goal %ld\n", dist[gy][gx]);
            pushHeap(nx, ny, dist, que);
            }
        }
    }
    // ?????
    /*
    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < W; j++) {
            printf("%3ld ", dist[i][j]);
        }
        printf("\n");
    }
    */
    // ?????
    free(que);
    //printf("sy %d sx %d gy %d gx %d\n", sy, sx, gy, gx);
    return dist[gy][gx];
}
// ????
void BinarySearch(long **dist, char **s) {
    //printf("call BinarySearch\n");
    long low = 1, high = T;
    //printf("T %ld\n", T);
    long maxTime, cost;
    // ????
    while ((high-low) > 1) {
        cost = (low+high)/2;
        //printf("cost %ld\n", cost);
        maxTime = Dijkstra(cost, dist, s);
        //printf("maxTime %ld\n", maxTime);
        if (maxTime > T) {
            high = cost;
        } else {
            low = cost;
        }
        //printf("low %ld high %ld\n", low, high);
    }
    printf("%ld\n", low);
} ./Main.c: In function ‘main’:
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld\n", &H, &W, &T);
     ^
./Main.c: In function ‘setBoard’:
./Main.c:71:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%c", &s[i][j]);
             ^