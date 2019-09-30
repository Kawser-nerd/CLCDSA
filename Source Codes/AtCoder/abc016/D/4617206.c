#include <stdio.h>
#include <stdlib.h>
#define sizeN 101
int Ax, Ay, Bx, By; // ????????
int N; // ???????
// ??????
typedef struct vec {
    int vecx, vecy;
} vec_t;
// ?????????
vec_t directionVec (vec_t a, vec_t b) {
    vec_t direction;
    direction.vecx = b.vecx - a.vecx;
    direction.vecy = b.vecy - a.vecy;
    return direction;
}
// ?????
int crossProduct(vec_t a, vec_t b) {
    int product;
    product = a.vecx*b.vecy - b.vecx*a.vecy;
    return product;
}
// ????????????
int isCross (vec_t start, vec_t end, vec_t p[]) {
    int cross = 0;  // ???
    double S1, S2;  //?????
    // ????
    vec_t base, vec1, vec2;
    // ?????
    for (size_t i = 0; i < N; i++) {
        base = directionVec(start, end);
        vec1 = directionVec(start, p[i]);
        vec2 = directionVec(start, p[(i+1)%N]);
        S1 = 0.5*crossProduct(base, vec1);
        S2 = 0.5*crossProduct(base, vec2);
        if (S1*S2 < 0) {    // ??????
            base = directionVec(p[i], p[(i+1)%N]);
            vec1 = directionVec(p[i], start);
            vec2 = directionVec(p[i], end);
            S1 = 0.5*crossProduct(base, vec1);
            S2 = 0.5*crossProduct(base, vec2);
            if (S1*S2 < 0) {
                cross ++;
            }
        } else {
            continue;
        }
    }
    // printf("cross %d\n", cross);
    int ans = cross/2 +1;
    printf("%d\n", ans);
    return 0;
}

int main(int argc, char const *argv[]) {
    // ??
    vec_t start, end; // ?? ??
    vec_t *point;
    // ??
    scanf("%d %d %d %d", &start.vecx, &start.vecy, &end.vecx, &end.vecy);
    scanf("%d", &N);
    point = (vec_t *)malloc(sizeof(vec_t)*N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &point[i].vecx, &point[i].vecy);
    }
    // ??
    isCross(start, end, point);
    free(point);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:60:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d", &start.vecx, &start.vecy, &end.vecx, &end.vecy);
     ^
./Main.c:61:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:64:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &point[i].vecx, &point[i].vecy);
         ^