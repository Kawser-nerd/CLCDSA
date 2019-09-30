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
char s[25];
char tmp[] = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";

int check(void){
    int flag = 1;
    int i, j;
    for (i = 0; i < 20; i++){
        flag = 1;
        for (j = i; j < i + 20; j++){
            if (tmp[j] != s[j-i]){
                flag = 0;
            }
        }
        if (flag == 1) return i;
    }
}



int main(void){
    scanf("%s", s);
    char piano[7][5] = {"Si", "Do", "Re", "Mi", "Fa", "So", "La"};
    int i;
    int pianum = 0;
    i = check();
    for (int k = 0; k <= i; k++){
        if (tmp[k] == 'W'){
            pianum++;
        }
    }
    printf("%s\n", piano[pianum%7]);

    return 0;

} ./Main.c: In function ‘main’:
./Main.c:86:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^