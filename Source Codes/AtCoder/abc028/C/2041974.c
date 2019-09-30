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


int main(void){
    int input[5];
    int cnt = 0;
    int ans[60];
    int cnt2 = 0;
    for (int i = 0; i < 5; i++){
        scanf("%d", &input[i]);
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                if (i == j || j == k || i == k){
                    continue;
                }else{
                    ans[cnt] = input[i]+input[j]+input[k];
                    cnt++;
                }
            }
        }
    }
    qsort(ans, cnt, sizeof(int), descending_compare);
    for (int i = 1; i < cnt; i++){
        if (ans[i-1] != ans[i]){
            cnt2++;
        }
        if (cnt2 == 2){
            printf("%d\n", ans[i]);
            return 0;
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:74:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &input[i]);
         ^