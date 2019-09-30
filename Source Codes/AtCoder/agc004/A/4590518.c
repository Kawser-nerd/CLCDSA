#include <stdio.h>

int main(void)
{
    long int a[3], i, j;

    for(i=0;i<3;i++){
        scanf("%ld", &a[i]);
    }
    long int min=a[0]*a[1]*a[2];
        
    if(a[0]%2==0 || a[1]%2==0 || a[2]%2==0) printf("%d\n", 0);
    else{
        for(i=0;i<3;i++){
            for(j=i+1;j<3;j++){
                if(a[i]*a[j]<min) min=a[i]*a[j];
            }
        }
        printf("%ld\n", min);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld", &a[i]);
         ^