#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void find_way(char** map, int** can_go, int nx, int ny, int *rest_grad){
    can_go[ny][nx] = 0;
    if (nx+1 <= 9) {
        if (can_go[ny][nx+1]) {
            (*rest_grad)--;
            find_way(map, can_go, nx+1, ny, rest_grad);
        }
    }
    if (ny+1 <= 9) {
        if (can_go[ny+1][nx]) {
            (*rest_grad)--;
            find_way(map, can_go, nx, ny+1, rest_grad);
        }
    }
    if (nx-1 >= 0) {
        if (can_go[ny][nx-1]) {
            (*rest_grad)--;
            find_way(map, can_go, nx-1, ny, rest_grad);
        }
    }
    if (ny-1 >= 0) {
        if (can_go[ny-1][nx]) {
            (*rest_grad)--;
            find_way(map, can_go, nx, ny-1, rest_grad);
        }
    }
}

void solve(void){
    int grad_counter = 0, n = 10, flag = 0;
    char **map = (char **)malloc(sizeof(char *) * n);
    rep(n, i){
        map[i] = (char *)malloc(sizeof(char) * (n+1));
        scanf("%s", map[i]);
        rep(n, j) if (map[i][j] == 'o') grad_counter++;
    }
    rep(n, nx){
        if (flag) break;
        rep(n, ny){
            if (map[ny][nx] == 'o') continue;
            int **can_go = (int **)malloc(sizeof(int *) * n);
            rep(n, y){
                can_go[y] = (int *)malloc(sizeof(int) * n);
                rep(n, x){
                    if (map[y][x] == 'o') {
                        can_go[y][x] = 1;  //???True
                    }
                    else can_go[y][x] = 0;  //???False
                }
            }
            int *rest_grad = (int *)malloc(sizeof(int));
            *rest_grad = grad_counter;
            find_way(map, can_go, nx, ny, rest_grad);
            if (*rest_grad == 0) {
                flag = 1; break;
            }
        }
    }
    if (flag) printf("YES\n");
    else printf("NO\n");
}

int main(void){
  solve();
  return 0;
} ./Main.c: In function ‘solve’:
./Main.c:42:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", map[i]);
         ^