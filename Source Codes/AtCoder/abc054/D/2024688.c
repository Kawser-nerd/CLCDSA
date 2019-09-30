#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    if (*(int*)a > *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}

int ascending_compare(const void *a, const void *b){
    if (*(int*)a < *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}


int lower_bound(int *a, int n, int key){
    int left, mid, right;
    left = 0, right = n;
    mid = (left + right)/2;
    while ((left+1 != mid || mid+1 != right) && mid != left){
        if (key > a[mid]){
            left = mid;
        }else{
            right = mid+1;
        }
        mid = (left + right)/2;
    }
    if (a[left] >= key)return left;
    if (a[mid] >= key)return mid;
    if (a[right] >= key)return right;
    return n;
}

//greatest common divisor
unsigned long  gcd(unsigned long x, unsigned long y){
    if (y == 0){ 
        return x;
    }else if (x > y){
        return gcd(y, x % y);
    }else{
        return gcd(x, y % x);
    }
}



long long factorial(int x){
    long long rtn = 1;
    int i;
    for (i = x; i > 1; i--){
        rtn = (rtn*i);
    }
    return rtn;
}
int edge[15][15] = {0};
int v[15] = {0};
int cnt = 0;
int n, m;

int dfs(int now){
    int flag = 1;
    for (int i = 1; i <= n; i++){
        if (v[i] != 1){
            flag = 0;
        }
    }
    if (flag == 1){
        cnt++;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        if (edge[now][i] == 1 && v[i] != 1){
            v[i] = 1;
            dfs(i);
            v[i] = 0;
        }
    }
    return 0;
}
int dp[401][401] = {0};
int a[40];
int b[40];
int c[40];



int main(void){
    int n, ma, mb;
    int min = 1000000000;
    scanf("%d %d %d", &n, &ma, &mb);
    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
    dp[0][0] = 1;
    for (int k = 0; k < n; k++){
        for (int i = 400; i >= 0; i--){
            for (int j = 400; j >= 0; j--){
                if (i-a[k] > -1 && j-b[k] > -1 && dp[i-a[k]][j-b[k]] > 0){
                    if (dp[i][j] == 0 ||  c[k] + dp[i-a[k]][j-b[k]] < dp[i][j]){
                        dp[i][j] = c[k] + dp[i-a[k]][j-b[k]];
                    }
                }
            }
        }
    }
    for (int i = 1; i < 401; i++){
        for (int j = 1; j < 401; j++){
            if (dp[i][j] > 0 && i * mb == j * ma){
                if (dp[i][j] < min){
                    min = dp[i][j];
                }
            }
        }
    }
    if (min == 1000000000){
        printf("-1\n");
        return 0;
    }
    printf("%d\n", min-1);



    return 0;

} ./Main.c: In function ‘main’:
./Main.c:101:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &ma, &mb);
     ^
./Main.c:103:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &a[i], &b[i], &c[i]);
         ^