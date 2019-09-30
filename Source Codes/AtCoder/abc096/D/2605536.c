#include <stdio.h>
#define MAX 55

int p_judge(int x) {
    int i=2;
    while(x>=i*i) {
        if(x%i==0)
            return 0;
        i++;
    }
    return 1;
}

int main(void) {
    int n, i, j=0, k;
    int a[MAX];
    scanf("%d", &n);
    
    for(i=11; i<=55555; i+=10) {
        if(p_judge(i)==1) {
            a[j] = i;
            j++;
            if(j==n) {
                for(k=0; k<n; k++) {
                    printf("%d ", a[k]);
                }
                return 0;
            }
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^