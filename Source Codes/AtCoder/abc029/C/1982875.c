#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve(void){
    int n, kouhosu = 1; //???
    scanf("%d\n", &n);
    rep(n, i) kouhosu *= 3;

    char **pw = (char **)malloc(sizeof(char *) * kouhosu+1);  //passwords
    rep(kouhosu, i) pw[i] = (char *)malloc(sizeof(char) * (n+1));

    char ws[3] = "abc";
    int length = n;

    while(length) {
        int k = n - length;
        int ser = 1;
        rep(length-1, j) ser *= 3;
        rep(kouhosu, i) pw[i][k] = ws[(i/ser)%3];
        length--;
    }

    rep(kouhosu, i){
        rep(n, j) printf("%c", pw[i][j]);
        printf("\n");
    }
}

int main(void){
  solve();
  return 0;
} ./Main.c: In function ‘solve’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &n);
     ^