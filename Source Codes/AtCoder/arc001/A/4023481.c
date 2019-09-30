#include <stdio.h>
#include <stdlib.h>

int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

int main(){
    int n, ans[4] = {0}, i, max, min;
    char *c;

    scanf("%d", &n);

    c = (char *) malloc(sizeof(char) * (n + 1));
    scanf("%s", c);

    for(i = 0; i <= n; i++){
        ans[ctoi(c[i]) - 1]++;
    }

    free(c);

    max = ans[0];
    min = ans[0];
    for(i = 1; i < 4; i++){
        if(max < ans[i])
            max = ans[i];
        if(ans[i] < min)
            min = ans[i];
    }

    printf("%d %d\n", max, min);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", c);
     ^