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
    char s[15];
    int j = 0;
    int pre = 0;
    char tmp[15];
    int pattern;
    int len;
    long long ans = 0;

    scanf("%s", s);
    len = strlen(s);
    for (int i = 0; i < 1 << (len-1); i++){
        j = 1;
        pre = 0;
        pattern = i;
        pattern += 1 << len;
        while (pattern != 0){
            if ((pattern & 1) == 1){
                for (int k = 0; k < j - pre; k++){
                    tmp[k] = s[k+pre];
                    tmp[k+1] = '\0';
                }
                pre = j;
                ans += atoll(tmp);
            }
            pattern = pattern >> 1;
            j++;
        }
    }
    printf("%lld\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:81:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^