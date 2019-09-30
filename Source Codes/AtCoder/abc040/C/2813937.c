#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    int c[n],tmp;
    for (int i=0; i<n; i++){
        if (i==0){
            c[i]=0;
        } else if (i==1) {
            c[i]=abs(a[i]-a[i-1]);
        } else {
            tmp=0;
            c[i]=c[i-1]+abs(a[i]-a[i-1]);
            tmp =c[i-2]+abs(a[i]-a[i-2]);
            if (tmp<c[i]){
                c[i]=tmp;
            }
        }
    }
    printf("%d\n",c[n-1]);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^