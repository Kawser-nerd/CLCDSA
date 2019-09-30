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
int zatsu[100000];
int zipped[100000];
int nums[100000];
int a[100000];



int main(void){
    int n;
    int cnt = 0;
    int j = 0;
    int *tmp;
    nums[0] = 0;
    nums[1] = 1;
    for (int i = 2; i < 100000; i++){
        nums[i] = nums[i-1]+1;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        zatsu[i] = a[i];
    }
    qsort(a, n, sizeof(int), ascending_compare);
    a[n] = -1;
    for (int i = 0; i < n; i++){
        if (a[i] != a[i+1]){
            zipped[j] = a[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++){
        tmp = (int *)bsearch(&zatsu[i], zipped, j, sizeof(int), ascending_compare);
        printf("%ld\n", tmp-zipped);
    }


} ./Main.c: In function ‘main’:
./Main.c:84:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:86:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^