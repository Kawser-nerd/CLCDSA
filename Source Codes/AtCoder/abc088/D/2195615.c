#include <stdio.h>
void length(int x, int y, int len_in_adv, int W, int H, char s[W][H], int visited[W][H]);
int ret;

int main(){
    int W, H;
    int x, y;
    int white = 0;
    char temp;
    scanf("%d %d\n", &H, &W);

    char s[W][H];
    int visited[W][H];

    for(y = 0; y < H; ++y){
        for(x = 0; x < W; ++x){
            visited[x][y] = H * W + 1;

            scanf("%c", &s[x][y]);
            if(s[x][y] == '.'){
                white++;
            }
        }
        if(y < H - 1){
            scanf("%c", &temp);
        }
    }

    ret  = H * W + 1;
    length(0, 0, 1, W, H, s, visited);

    if(ret  == H * W + 1){
        printf("-1\n");
    }else{
        printf("%d\n", white - ret);
    }
    return 0;
}

void length(int x, int y, int len_in_adv, int W, int H, char s[W][H], int visited[W][H]){
    visited[x][y] = 1;

    if(len_in_adv >= ret ||
    x > W - 1||x < 0||
    y > H - 1 || y < 0){
        return;
    }

    if(x == W - 1 && y == H - 1){
        if(len_in_adv < ret){
            ret = len_in_adv;
        }
        return;
    }
    if(y + 1 < H && s[x][y + 1] == '.' && visited[x][y + 1] > len_in_adv + 1){
        length(x, y + 1, len_in_adv + 1, W, H, s, visited);
        visited[x][y + 1] = len_in_adv + 1;
    }
    if(y - 1 >= 0 && s[x][y - 1] == '.' && visited[x][y - 1] > len_in_adv + 1){
        length(x, y - 1, len_in_adv + 1, W, H, s, visited);
        visited[x][y - 1] = len_in_adv + 1;
    }
    if(x + 1 < W && s[x + 1][y] == '.' && visited[x + 1][y] > len_in_adv + 1){
        length(x + 1, y, len_in_adv + 1, W, H, s, visited);
        visited[x + 1][y] = len_in_adv + 1;
    }
    if(x - 1 >= 0 && s[x - 1][y] == '.' && visited[x - 1][y] > len_in_adv + 1){
        length(x - 1, y, len_in_adv + 1, W, H, s, visited);
        visited[x - 1][y] = len_in_adv + 1;
    }
    return;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d\n", &H, &W);
     ^
./Main.c:19:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%c", &s[x][y]);
             ^
./Main.c:25:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%c", &temp);
             ^