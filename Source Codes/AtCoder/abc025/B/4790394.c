#include <stdio.h>
#include <string.h>
// ??
int N, A, B;
// ???????
int Dist (int d) {
    int dist = 0;
    if (d < A) {
        dist = A;
    } else if (B < d) {
        dist = B;
    } else {
        dist = d;
    }
    return dist;
}

// ???
int main(int argc, char const *argv[]) {
    scanf("%d %d %d", &N, &A, &B);
    char s[6];
    int d;
    int dist = 0;
    for (size_t i = 0; i < N; i++) {
        scanf("%s", s);
        scanf("%d", &d);
        char e[] = "East";
        int flag = 0;
        if (strcmp(s, e)!=0) {  // ?????
            flag = -1;
        }
        if (flag == -1) {
            dist -= Dist(d);
        } else {
            dist += Dist(d);
        }
    }
    // ??
    if (dist > 0) {
        printf("East %d\n", dist);
    } else if (dist < 0) {
        printf("West %d\n", -dist);
    } else {
        printf("0\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &N, &A, &B);
     ^
./Main.c:25:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", s);
         ^
./Main.c:26:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &d);
         ^