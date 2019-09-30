#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
    int n,q;
    scanf("%d%d",&n,&q);
    int a[n],start[n],end[n];
    for (int i=0; i<n; i++){
        a[i]=0;
        start[i]=0;
        end[i]=0;
    }
    int l[q],r[q];
    for (int i=0; i<q; i++){
        scanf("%d%d",&l[i],&r[i]);
        start[l[i]-1]++;
        end[r[i]-1]++;
    }
    for (int i=0; i<n; i++){
        a[i]+=start[i];
        start[i+1]+=start[i];
        if (i!=0) {
            a[i]-=end[i-1];
            end[i]+=end[i-1];
        }
        printf("%d",a[i]%2);
    }
    printf("\n");
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&q);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&l[i],&r[i]);
         ^