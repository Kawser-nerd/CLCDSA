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
int dp[41][401][401];
int a[41];
int b[41];
int c[41];



int main(void){
    int n, ma, mb;
    int min = 1000000000;
    scanf("%d %d %d", &n, &ma, &mb);
    for (int i = 1; i <= n; i++){
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
    for (int i = 0; i < 41; i++){
        for (int j = 0; j < 401; j++){
            for (int k = 0; k < 401; k++){
                dp[i][j][k] = min;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 401; j++){
            for (int k = 0; k < 401; k++){
                if (dp[i-1][j][k] != min){
                    if (dp[i][j+a[i]][k+b[i]] > dp[i-1][j][k] + c[i]){
                        dp[i][j+a[i]][k+b[i]] = dp[i-1][j][k] + c[i];
                    }
                    if (dp[i][j][k] > dp[i-1][j][k]){
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
    }

    for (int i = 1; i < 401; i++){
        for (int j = 1; j < 401; j++){
            if (dp[n][i][j] < min && mb*i == ma*j){
                min = dp[n][i][j];
            }
        }
    }
    if (min == 1000000000){
        printf("-1\n");
    }else{
        printf("%d\n", min);  
    }
    



    return 0;

} ./Main.c: In function ‘main’:
./Main.c:76:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &ma, &mb);
     ^
./Main.c:78:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &a[i], &b[i], &c[i]);
         ^