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

unsigned long  gcd(unsigned long x, unsigned long y)
{
        if (y == 0) {
                return x;
        } else {
                return gcd(y, x % y);
        }
}



long long calc(int x){
    long long rtn = 1;
    int i;
    for (i = x; i > 1; i--){
        rtn = (rtn*i);
    }
    return rtn;
}



int main(void){
    int n;
    int even = 0;
    int odd = 0;
    int a;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &a);
        if (a % 2 == 0){
            even++;
        }else{
            odd++;
        }
    }

    even += odd/2;
    odd = odd % 2;
    while (even > 1){
        even = even/2 + even%2;
    }
    if (even + odd == 1){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:73:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:75:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^