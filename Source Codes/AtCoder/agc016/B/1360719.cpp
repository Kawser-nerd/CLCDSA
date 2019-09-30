#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, a[100000+10];
int main() {
    scanf("%d", &n);
    int ok = 1;
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        if(a[i] != n-1) {
            ok = 0;
        }
    }
    if(ok) {
        printf("Yes\n");
        return 0;
    }
    int c = *max_element(a+1, a+1+n);
    
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        if(c - a[i] >= 2) {
            printf("No\n");
            return 0;
        }

        if(c - a[i] == 1) {
            cnt ++;
        }
    }

    if((n-cnt) < 2*(c-cnt) || (cnt >= c)) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
}