#include <stdio.h>
#include <stdlib.h>

static int compare(const void* a, const void* b)
{
    int aNum = *(int*)a;
    int bNum = *(int*)b;

    return aNum-bNum;
}

int main(void)
{
    int n, l[200], i, sum=0;

    scanf("%d", &n);

    for(i=0;i<2*n;i++){
        scanf("%d", &l[i]);
    }

    qsort(l, 2*n, sizeof(int), compare);
    
    for(i=0;i<2*n;i++){
        if(i%2==0 || i==0) sum=sum+l[i];
    }

    printf("%d\n", sum);
        

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &l[i]);
         ^