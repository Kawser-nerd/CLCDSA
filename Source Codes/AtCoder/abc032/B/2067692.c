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

/*
int struct_ascending_compare(const void *p, const void *q) {
    return ((struct_name*)p)->member_name - ((struct_name*)q)->member_name;
}*/
char field[55][55];
int queue[1000000] = {0};
int d[55][55];
int head = 0;
int tail = 0;
void enqueue(int a){
    queue[tail] = a;
    tail++;
}
int dequeue(void){
    head++;
    return queue[head-1];
}

char s[305];
char ans[305][305];

int main(void){
    scanf("%s", s);
    int k;
    int cnt = 0;
    scanf("%d", &k);
    int len = strlen(s);
    for (int i = 0; i <= len - k; i++){
        for (int j = i; j < i + k; j++){
            ans[i][j-i] = s[j];
            ans[i][j-i+1] = '\0';
        }
    }
    for (int i = 0; i <= len - k; i++){
        int flag = 1;
        for (int j = i-1; j >= 0; j--){
            if (strcmp(ans[i], ans[j]) == 0){
                flag = 0;
            }
        }
        if (flag == 1){
            cnt++;
        }
    }

    printf("%d\n", cnt);

} ./Main.c: In function ‘main’:
./Main.c:90:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
./Main.c:93:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &k);
     ^