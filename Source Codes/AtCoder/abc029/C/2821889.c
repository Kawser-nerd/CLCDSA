#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    int n,q=1;
    scanf("%d",&n);
    int a[n];
    char p[4]="abc";
    for (int i=0; i<n; i++){
        a[i]=0;
        q*=3;
    }
    for (int i=0; i<q; i++){
        for (int i=0; i<n; i++){
            printf("%c",p[a[i]]);
        }
        printf("\n");
        a[n-1]++;
        for (int i=0; i<n; i++){
            if(a[n-i-1]==3){
                a[n-i-1]=0;
                a[n-i-2]++;
            }
        }
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^