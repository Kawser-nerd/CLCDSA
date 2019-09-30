#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct{
    
    long int a;
    long int b;
    
}NUMBER;

int compare(const void *a, const void *b)
{
   NUMBER aNum = *(NUMBER*)a;
   NUMBER bNum = *(NUMBER*)b;

    int tmp1=aNum.a;
    int tmp2=bNum.a;

    return tmp1-tmp2;
}

int main(void)
{
    long int n, k, i, j=0;
    scanf("%ld%ld", &n, &k);
    NUMBER array[10*10*10*10*10];
    for(i=0;i<n;i++){
        scanf("%ld%ld", &array[i].a, &array[i].b);
    }

    qsort(array, n, sizeof(NUMBER), compare);
    for(i=0;i<n;i++){
        j=j+array[i].b;
        if(j>=k) break;
    }

    printf("%ld\n", array[i].a);
   
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld", &n, &k);
     ^
./Main.c:28:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld%ld", &array[i].a, &array[i].b);
         ^