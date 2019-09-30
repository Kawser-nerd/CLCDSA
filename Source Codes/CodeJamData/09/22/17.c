#include <stdio.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int t, i, j, a[50];
    char n[50];
    scanf("%d", &t);
    for(i = 1; i <= t; i++) {
        scanf("%s", n);
        for(j = 0; j < strlen(n); j++) {
            a[j] = n[j] - '0';
        }
      //  printf("%d\n", j);
        int k, ok = 0;
        for(k = j-1; k > 0; k--) {
            if(a[k] > a[k-1]) {
                ok = 1;
                break;
            }
        }
     //   printf("ok:%d\n", ok);
        if(ok == 1) {
            int ii;
            for(ii = j-1; ii>=k; ii--) {
                if(a[ii]>a[k-1]) {
                    break;
                }
            }
            int tt=a[ii];a[ii]=a[k-1];a[k-1]=tt;
           // printf("%d %d\n", k, j);
            qsort(a+k, j-k, sizeof(int), cmp);
        }
        else {
            a[j++] = 0;
           // printf("newJ:%d\n", j);
            qsort(a, j, sizeof(int), cmp);
            int kk;
            for(kk = 0; kk<j;kk++) {
                if(a[kk]>0)
                    break;
            }
            int tt=a[0];a[0]=a[kk];a[kk]=tt;
        }
        printf("Case #%d: ", i);
        for(k = 0;k < j; k++) {
            printf("%d", a[k]);
        }
        printf("\n");
    }
    return 0;
}
