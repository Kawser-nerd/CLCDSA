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

long long a[100005];

int main(void){
    int n;
    long long ans = 0;
    long long ans2 = 0;
    long long sum;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }

    if (a[0] <= 0){
        sum = 1;
        ans = llabs(1 - a[0]);
    }else{
        sum = a[0];
    }
    for (int i = 1; i < n; i++){
        if (sum+a[i] == 0){
            sum = (-1*llabs(sum)/sum);
            ans++;
        }else if (llabs(sum+a[i])/(sum+a[i]) == llabs(sum)/sum){
            ans += llabs(a[i] - ((-1*llabs(sum)/sum) - sum));
            sum = (-1*llabs(sum)/sum);
        }else{
            sum += a[i];
        }
    }
    if (a[0] >= 0){
        sum = -1;
        ans2 = llabs(-1 - a[0]);
    }else{
        sum = a[0];
    }
    for (int i = 1; i < n; i++){
        if (sum+a[i] == 0){
            sum = (-1*llabs(sum)/sum);
            ans2++;
        }else if (llabs(sum+a[i])/(sum+a[i]) == llabs(sum)/sum){
            ans2 += llabs(a[i] - ((-1*llabs(sum)/sum) - sum));
            sum = (-1*llabs(sum)/sum);
        }else{
            sum += a[i];
        }
    }
    

    printf("%lld\n", ans>ans2?ans2:ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:74:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:76:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &a[i]);
         ^