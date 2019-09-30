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

unsigned long long s[100005];


int main(void){
    int n, k;
    int ans = 0;
    int cnt = 0;
    int end = 0;
    int flag = 0;
    unsigned long long total = 1;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%llu", &s[i]);
        if (s[i] == 0){
            flag = 1;
        }
    }
    if (flag){
        printf("%d\n", n);
        return 0;
    }
    for (int i = 0; i < n; i++){
        while (end < n && total * s[end] <= k){
            total *= s[end];
            cnt++;
            end++;
        }
        ans = ans<cnt?cnt:ans;
        if (s[end] > k){
            end++;
        }else{
            total /= s[i];
            cnt--;
        }
    }

    printf("%d\n", ans);



    return 0;
} ./Main.c: In function ‘main’:
./Main.c:77:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &k);
     ^
./Main.c:79:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%llu", &s[i]);
         ^