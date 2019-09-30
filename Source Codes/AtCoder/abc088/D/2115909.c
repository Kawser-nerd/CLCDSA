#include<stdio.h>

#define INF 100000000

int h, w;
char s[50][50];
int dp[50][50];

int min(int a, int b)
{
    if(a > b) return b;
    else return a;
}

int main()
{
    int i, j, k;
    char buf[64];
    int white_num = 0;
    int ans;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int x, y;
    int cnt = 0;

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d %d", &h, &w);

    for(i = 0; i < h; i++){
        fgets(buf, sizeof(buf), stdin);
        for(j = 0; j < w; j++) s[i][j] = buf[j];
    }

    for(i = 0; i < h; i++) for(j = 0; j < w; j++)
        if(s[i][j] == '.') white_num++;

    for(i = 0; i < h; i++) for(j = 0; j < w; j++)
        dp[i][j] = INF;
    dp[0][0] = 0;
    while(dp[h-1][w-1] == INF){
        for(i = 0; i < h; i++) for(j = 0; j < w; j++){
            if(s[i][j] == '#') continue; 
            for(k = 0; k < 4; k++){
                x = j + dx[k]; y = i + dy[k];
                if(0 <= x && x < w && 0 <= y && y < h && s[y][x] == '.'){
                    dp[i][j] = min(dp[i][j], dp[y][x]+1);
                }
            }
            cnt++;
        }
        if(cnt > INF) break;
    }

    if(dp[h-1][w-1] == INF) ans = -1;
    else ans = white_num - (dp[h-1][w-1]+1);
    printf("%d\n", ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf, sizeof(buf), stdin);
     ^
./Main.c:30:9: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
         fgets(buf, sizeof(buf), stdin);
         ^