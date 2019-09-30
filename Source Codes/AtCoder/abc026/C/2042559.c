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

int e[21][21] = {0};
int m[21] = {0};
unsigned long long v[21] = {0};

int main(void){
    int n;
    int max;
    int min;
    int tmp;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++){
        scanf("%d", &tmp);
        e[tmp][i] = 1;
        m[tmp]++;
    }

    for (int i = n; i > 0; i--){
        if (m[i] == 0){
            v[i] = 1;
        }
    }
    for (int i = n; i > 0; i--){
        min = -1;
        max = -1;
        if (m[i] == 0){
            continue;
        }
        for (int j = n; j > 0; j--){
            if (e[i][j] == 1){
                if (max < v[j] || max == -1){
                    max = v[j];
                }
                if (min > v[j] || min == -1){
                    min = v[j];
                }
            }
        }
        v[i] = min + max + 1;
    }

    printf("%d\n", v[1]);



} ./Main.c: In function ‘main’:
./Main.c:107:12: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long unsigned int’ [-Wformat=]
     printf("%d\n", v[1]);
            ^
./Main.c:76:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:78:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &tmp);
         ^