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
int s[55];
int main(void){
    int n;
    int takahashi = -50000000;
    int tmp;
    int tmpi;
    int maxi;
    int maxaoki;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < n; i++){
        maxaoki = -50000000;
        for (int j = 0; j < n; j++){
            tmp = 0;
            if (i == j){
                continue;
            }else{
                if (i < j){
                    for (int k = i + 1; k <= j; k += 2){
                        tmp += s[k];
                    }
                }else{
                    for (int k = j + 1; k <= i; k += 2){
                        tmp += s[k];
                    }
                }
            }
            if (tmp > maxaoki){
                maxaoki = tmp;
                tmpi = j;
            }else if (tmp == maxaoki && j < tmpi){
                tmpi = j;
            }
        }
        tmp = 0;
        if (tmpi > i){
            for (int k = i; k <= tmpi; k += 2){
                tmp += s[k];
            }
            if (takahashi < tmp){
                takahashi = tmp;
            }
        }else{
            for (int k = tmpi; k <= i; k += 2){
                tmp += s[k];
            }
            if (takahashi < tmp){
                takahashi = tmp;
            }
        }
    }
    

    printf("%d\n", takahashi);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:75:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:77:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &s[i]);
         ^