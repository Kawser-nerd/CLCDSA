#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(void){
    int a[3],i;
    for(i=0;i<3;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,3,sizeof(int),compare);
    printf("%d\n",a[1]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^